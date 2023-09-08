#include "musica.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "wave/file.h"

using namespace std;

Nota::Nota(Cifrado nota, int octava)
{
    m_nota = nota;
    m_octava = octava;
    m_figura = Figura::Negra;
}

Nota::Nota(Cifrado nota, int octava, Figura figura)
{
    m_nota = nota;
    m_octava = octava;
    m_figura = figura;
}

Nota::Nota(int id, Figura figura)
{
    m_nota = (Cifrado)(id % 12);
    m_octava = id / 12;
    m_figura = figura;
}

int Nota::id()
{
    return m_octava * 12 + (int)m_nota;
}

Nota Nota::bemol()
{
    return Nota(id() - 1, m_figura);
}

Nota Nota::sostenido()
{
    return Nota(id() + 1, m_figura);
}

Nota Nota::tercera()
{
    return Nota(id() + 4, m_figura);
}

Nota Nota::quinta()
{
    return Nota(id() + 7, m_figura);
}

Nota Nota::septima()
{
    return Nota(id() + 11, m_figura);
}

Nota Nota::octava()
{
    return Nota(id() + 12, m_figura);
}

double Nota::frecuencia()
{
    return 440.0 * pow(semitono, id() - A4_id);
}

string Nota::nombre()
{
    string notas[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    return notas[(int)m_nota] + to_string(m_octava);
}

double ruidoPerlin(double x)
{
    // Fixme: TODO
    return 0;
}

double oscilar(double argumento, Onda onda)
{
    double sample = 0.0;
    switch (onda)
    {
    case SENO:
        return sin(argumento);
    case CUADRADA:
        return sin(argumento) > 0.0 ? 1.0 : -1.0;
    case TRIANGULAR:
        return 2 * asin(sin(argumento)) / M_PI;
    case SERRUCHO:
        for (int i = 1; i <= 20; i++)
            sample += sin(argumento * i) / i;
        return 2 * sample / M_PI;
    case RUIDO:
        return ruidoPerlin(argumento);
    default:
        return 0;
    }
}

double Nota::sample(double t, Armonicos armonicos, Onda onda)
{
    double sample = 0;
    int i = 1;
    for (double amplitud : armonicos)
    {
        sample += amplitud * oscilar(t * 2.0 * M_PI * frecuencia() * i, onda);
        i++;
    }

    return sample;
}

double Nota::duracion(int pulso)
{
    double duracionExacta = (double)m_figura * 60.0 / (pulso * 4.0);
    return round(frecuencia() * duracionExacta) / frecuencia();
    // return duracionExacta;
}

Acorde::Acorde(Nota base, bool menor, bool septima, bool septimaMenor)
{
    m_base = base;
    m_figura = base.figura();
    m_terceraMenor = menor;
    m_septima = septima;
    m_septimaMenor = septimaMenor;
}

// Fixme: implementar acordes disminuidos
vector<Nota> Acorde::notas()
{
    vector<Nota> basico = {m_base, m_base.tercera(), m_base.quinta()};

    if (m_terceraMenor)
        basico[1] = basico[1].bemol();

    if (m_septima)
    {
        basico.push_back(m_base.septima());
        if (m_septimaMenor)
            basico[3] = basico[3].bemol();
    }

    return basico;
}

double Acorde::sample(double t, Armonicos armonicos, Onda onda)
{
    double sample = 0;
    for (Nota nota : notas())
        sample += nota.sample(t, armonicos, onda);
    return sample / notas().size();
}

// TODO: implementar el puntillo
double Acorde::duracion(int pulso)
{
    double mejorDuracion = 0.0;
    for (Nota nota : notas())
        mejorDuracion += nota.duracion(pulso);

    return mejorDuracion / notas().size();
}

LineaMusical::LineaMusical(vector<Evento *> eventos)
{
    m_eventos = eventos;
    actualizarDuracion();
}

void LineaMusical::agregar(Evento *evento)
{
    m_eventos.push_back(evento);
    m_duracion += evento->duracion(m_pulso);
}

void LineaMusical::setearPulso(int pulso)
{
    m_pulso = pulso;
    actualizarDuracion();
}

void LineaMusical::actualizarDuracion()
{
    m_duracion = 0;
    for (Evento *evento : m_eventos)
        m_duracion += evento->duracion(m_pulso);
}

void LineaMusical::proximoEvento(double tiempo)
{
    // cout << "Terminé un evento de duración " << eventoActual()->m_figura << endl;
    // m_eventoInicio += eventoActual()->duracion(m_pulso);
    m_eventoInicio = tiempo;
    m_eventoIndex++;
}

double samplearAux(double tiempo, Envolvente envolvente){
    double amplitud = 0.0;

    if (tiempo < 0)
        amplitud = 0.0;
    // Ataque
    else if (tiempo <= envolvente.tiempoAtaque)
        amplitud = (tiempo / envolvente.tiempoAtaque) * envolvente.nivelAtaque;

    // Decaer
    else if (tiempo <= envolvente.tiempoAtaque + envolvente.tiempoDecaer)
        amplitud = ((tiempo - envolvente.tiempoAtaque) / envolvente.tiempoDecaer) * (envolvente.nivelSostener - envolvente.nivelAtaque) + envolvente.nivelAtaque;

    // Sostener
    else
        amplitud = envolvente.nivelSostener;

    return amplitud;
}

double LineaMusical::samplearEnvolvente(double tiempo, double duracionTotal)
{
    double amplitud = 0.0;

    double soltar = duracionTotal - m_envolvente.tiempoSoltar;
    if (tiempo < soltar)
        amplitud = samplearAux(tiempo, m_envolvente);
    else
        amplitud = samplearAux(soltar, m_envolvente) * (1 - (tiempo-soltar)/m_envolvente.tiempoSoltar);

    return amplitud;
}

double LineaMusical::samplear(double tiempo, bool debug = false)
{
    double t = tiempo - m_eventoInicio;
    if (t >= eventoActual()->duracion(m_pulso))
    {
        cout << "====================================================" << endl;
        cout << "Pasando de evento " << tiempo << " " << m_eventoInicio << " " << eventoActual()->duracion(m_pulso) << endl;
        proximoEvento(tiempo);
    }

    if (terminado())
        return 0.0;

    double sample = eventoActual()->sample(t, m_armonicos, m_onda) * samplearEnvolvente(t, eventoActual()->duracion(m_pulso));

    if (debug)
        cout << "t: " << t << "  nota: " << eventoActual()->sample(t, m_armonicos, m_onda) << "  envolvente: " << samplearEnvolvente(t, eventoActual()->duracion(m_pulso)) << "  sample: " << sample << '\n';

    return sample;
}

vector<float> Cancion::producirSamples()
{
    const int bitrate = 44100;
    const double step = 1.0 / double(bitrate);

    double sample = 0.0;
    double t = 0.0;
    int n = 0;
    
    // La duracion total es el maximo de las duraciones de los canales
    double duracionTotal = 0.0;
    for (auto &canal : m_canales){
        canal.principio();
        duracionTotal = max(duracionTotal, canal.duracion());
    }

    int N_samples = ceil(duracionTotal * bitrate);
    auto samples = vector<float>(N_samples);

    for (int i = 0; i < N_samples; i++)
    {
        sample = 0.0;
        for (auto &canal : m_canales)
            sample += canal.samplear(t);

        samples[i] = (float) sample;
        t += step;
    }

    cout << "Terminé de samplear la canción!" << endl;

    return samples;
}

void Cancion::producirRaw(string nombre)
{
    ofstream archivo;
    archivo.open(nombre, ios::binary);
    if (!archivo)
    {
        cerr << "No se pudo abrir el archivo " << nombre << endl;
        return;
    }

    auto content = producirSamples();
    archivo.write((char *)&content[0], content.size() * sizeof(float));
    archivo.close();
}

void Cancion::producirWave(string nombre) {
    wave::File archivo;
    wave::Error err = archivo.Open(nombre, wave::kOut);

    if (err) {
        cerr << "No se pudo abrir el archivo " << nombre << endl;
        return;
    }

    archivo.set_sample_rate(44100);
    archivo.set_bits_per_sample(16);
    archivo.set_channel_number(1);

    auto content = producirSamples();
    cout << "Sampleado!" << content[200] << endl;
    archivo.Write(content);
}