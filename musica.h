#pragma once

#include <string>
#include <vector>

using namespace std;

enum Cifrado
{
    C,
    CS,
    D,
    DS,
    E,
    F,
    FS,
    G,
    GS,
    A,
    AS,
    B
};

enum Figura
{
    Redonda = 16,
    Blanca = 8,
    Negra = 4,
    Corchea = 2,
    Semicorchea = 1
};

enum Onda
{
    SENO,
    CUADRADA,
    TRIANGULAR,
    SERRUCHO,
    RUIDO
};

typedef struct Envolvente
{
    double tiempoAtaque = 0.0001;
    double tiempoDecaer = 0.0001;
    double tiempoSoltar = 0.01;

    double nivelSostener = 0.9;
    double nivelAtaque = 1.0;
} Envolvente;

typedef vector<double> Armonicos;

double const semitono = 1.0594630943592952645618252949463417007792043174941856285592084314;

class Evento
{
protected:
public:
    Figura m_figura;
    virtual double duracion(int pulso) { return 0; }
    virtual double sample(double t, Armonicos armonicos, Onda onda) { return 0; }
};

class Nota : public Evento
{
private:
    Cifrado m_nota;
    int m_octava;

    static const int A4_id = 4 * 12 + (int)Cifrado::A;

public:
    Nota() {}
    Nota(Cifrado nota, int octava);
    Nota(Cifrado nota, int octava, Figura figura);
    Nota(int id, Figura figura);

    Figura figura() { return m_figura; }

    string nombre();
    Nota tercera();
    Nota quinta();
    Nota septima();
    Nota octava();
    Nota sostenido();
    Nota bemol();
    int id();
    double frecuencia();

    double duracion(int pulso) override;
    double sample(double t, Armonicos armonicos, Onda onda) override;
};

class Acorde : public Evento
{
private:
    Nota m_base;
    bool m_terceraMenor;
    bool m_septima;
    bool m_septimaMenor;

public:
    Acorde(Nota base, bool menor = false, bool septima = false, bool septimaMenor = false);

    vector<Nota> notas();
    string nombre();
    Nota base() { return m_base; }

    double duracion(int pulso) override;
    double sample(double t, Armonicos armonicos, Onda onda) override;
};

class LineaMusical
{
protected:
    vector<Evento *> m_eventos;
    int m_pulso = 60;
    double m_duracion = 0;
    void actualizarDuracion();

    Envolvente m_envolvente;
    Armonicos m_armonicos = {1.0};
    Onda m_onda = Onda::SENO;

    int m_eventoIndex = 0;
    double m_eventoInicio = 0.0;

public:
    LineaMusical(vector<Evento *> eventos);
    vector<Evento *> eventos() { return m_eventos; }

    void setearPulso(int pulso);
    void setearArmonicos(Armonicos armonicos) { m_armonicos = armonicos; }
    void setearEnvolvente(Envolvente envolvente) { m_envolvente = envolvente; }
    void setearOnda(Onda onda) { m_onda = onda; }
    void agregar(Evento *evento);
    void agregarEn(Evento *evento, int index);

    double samplear(double tiempo, bool debug);
    double samplearEnvolvente(double tiempo, double duracionTotal);
    void producirRaw(string nombre);

    double duracion() { return m_duracion; }
    void principio()
    {
        m_eventoIndex = 0;
        m_eventoInicio = 0.0;
    }
    bool terminado() { return m_eventoIndex >= m_eventos.size(); }
    Evento *eventoActual() { return m_eventos[m_eventoIndex]; }
    void proximoEvento(double tiempo);
};

class Cancion
{
protected:
    vector<LineaMusical> m_canales;

public:
    Cancion(vector<LineaMusical> canales) : m_canales(canales){};

    void producirRaw(string nombre);
};