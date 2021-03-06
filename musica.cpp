#include "musica.h"
#include <math.h>
#include <iostream>
#include <fstream>

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
        return sin(argumento) > 0.0 ? 1.0: -1.0;
    case TRIANGULAR:
        return 2 * asin(sin(argumento)) / M_PI;
    case SERRUCHO:
        for (int i=1; i<=50; i++)
            sample += sin(argumento * i)/i;
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

// Fixme: implementar el puntillo
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

double LineaMusical::samplearEnvolvente(double tiempo, double duracionTotal)
{
    double amplitud = 0.0;

    // Ataque
    if (tiempo <= m_envolvente.tiempoAtaque)
        amplitud = (tiempo / m_envolvente.tiempoAtaque) * m_envolvente.nivelAtaque;
    // Decaer
    else if (tiempo > m_envolvente.tiempoAtaque && tiempo <= m_envolvente.tiempoAtaque + m_envolvente.tiempoDecaer)
        amplitud = ((tiempo - m_envolvente.tiempoAtaque) / m_envolvente.tiempoDecaer) * (m_envolvente.nivelSostener - m_envolvente.nivelAtaque) + m_envolvente.nivelAtaque;
    // Sostener
    else if (tiempo <= duracionTotal - m_envolvente.tiempoSoltar)
        amplitud = m_envolvente.nivelSostener;
    // Soltar
    else if (tiempo <= duracionTotal)
        amplitud = (1.0 - (tiempo - (duracionTotal - m_envolvente.tiempoSoltar)) / m_envolvente.tiempoSoltar) * m_envolvente.nivelSostener;

    // Descartar el final del Soltar
    if (amplitud < 0.0005)
        amplitud = 0.0;

    return amplitud;
}

void LineaMusical::producirRaw(string nombre)
{
    const int bitrate = 44100;

    ofstream archivo;
    archivo.open(nombre, ios::binary);
    if (!archivo)
    {
        cerr << "No se pudo abrir el archivo " << nombre << endl;
        return;
    }

    double step = 1.0 / double(bitrate);
    int eventoIndex = 0;
    double sample = 0.0;
    double t = 0.0;

    while (eventoIndex < m_eventos.size())
    {
        sample = m_eventos[eventoIndex]->sample(t, m_armonicos, m_onda) * samplearEnvolvente(t, m_eventos[eventoIndex]->duracion(m_pulso));
        archivo.write((char *)&sample, sizeof(double));
        t += step;

        if (t >= m_eventos[eventoIndex]->duracion(m_pulso))
        {
            t -= m_eventos[eventoIndex]->duracion(m_pulso);
            eventoIndex++;
        }
    }

    archivo.close();
}