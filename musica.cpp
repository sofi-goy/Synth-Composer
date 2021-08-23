#include "musica.h"
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;

Nota::Nota(Cifrado nota, int octava)
{
    m_nota = nota;
    m_octava = octava;
}

Nota::Nota(int id)
{
    m_nota = (Cifrado)(id % 12);
    m_octava = id / 12;
}

int Nota::id()
{
    return m_octava * 12 + (int)m_nota;
}

Nota Nota::bemol()
{
    return Nota(id() - 1);
}

Nota Nota::sostenido()
{
    return Nota(id() + 1);
}

Nota Nota::tercera()
{
    return Nota(id() + 4);
}

Nota Nota::quinta()
{
    return Nota(id() + 7);
}

Nota Nota::septima()
{
    return Nota(id() + 11);
}

Nota Nota::octava()
{
    return Nota(id() + 12);
}

double Nota::frecuencia()
{
    return 440.0 * pow(semitono, id() - Nota(Cifrado::A, 4).id());
}

string Nota::nombre()
{
    string notas[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    return notas[(int)m_nota] + to_string(m_octava);
}

double Nota::sample(double t)
{
    return sin(t * 2.0 * M_PI * frecuencia());
}

Acorde::Acorde(Nota base, bool menor, bool septima, bool septimaMenor)
{
    m_base = base;
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

double Acorde::sample(double t)
{
    double sample = 0;
    for (int i = 0; i < notas().size(); i++){
        sample += notas()[i].sample(t) / notas().size();
    }
    // sample = m_base.sample(t);
    return sample;
}

double Acorde::mejorDuracion(double duracionPedida)
{
    double mejorDuracion = 0.0;
    for (Nota nota : notas()){
        mejorDuracion += round(nota.frecuencia() * duracionPedida) / nota.frecuencia();
        cout << round(nota.frecuencia() * duracionPedida) / nota.frecuencia() << " ";
    }
    cout << endl << "=====" << endl;
    return mejorDuracion / notas().size();
}

// Fixme: implementar el puntillo
double Evento::duracion(int pulso)
{
    double duracionExacta = (double)m_figura * 60.0 / (pulso * 4.0);
    if (esSilencio())
        return duracionExacta;

    return m_acorde->mejorDuracion(duracionExacta);
}

Voz::Voz(vector<Evento> eventos)
{
    m_eventos = eventos;
    actualizarDuracion();
}

void Voz::agregar(Evento evento)
{
    m_eventos.push_back(evento);
    m_duracion += evento.duracion(m_pulso);
}

void Voz::setearPulso(int pulso)
{
    m_pulso = pulso;
    actualizarDuracion();
}

void Voz::actualizarDuracion()
{
    double tiempoAcumulado = 0;
    for (int i = 0; i < m_eventos.size(); i++)
    {
        tiempoAcumulado += m_eventos[i].duracion(m_pulso);
    }
    m_duracion = tiempoAcumulado;
}

void Voz::producirRaw(string nombre)
{
    const int bitrate = 44100;

    ofstream archivo;
    archivo.open(nombre, ios::binary);
    if (!archivo)
    {
        cerr << "No se pudo abrir el archivo " << nombre << endl;
        return;
    }

    int samples = floor(duracion() * double(bitrate));
    double step = 1.0 / double(bitrate);
    int eventoIndex = 0;
    double duracion = m_eventos[eventoIndex].duracion(m_pulso);
    double sample = 0.0;
    double t = 0.0;

    for (int i = 0; i < samples; i++)
    {
        if (t >= duracion){
            t -= duracion;
            eventoIndex++;
            duracion = m_eventos[eventoIndex].duracion(m_pulso);
        }
        if (m_eventos[eventoIndex].esSilencio())
            sample = 0.0;
        else
            sample = m_eventos[eventoIndex].acorde()->sample(t);
        archivo.write((char *)&sample, sizeof(double));
        t += step;
    }

    archivo.close();
}