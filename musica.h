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

class Nota
{
private:
    Cifrado m_nota;
    int m_octava;
    double semitono = 1.0594630943592952645618252949463417007792043174941856285592084314;

public:
    Nota() {}
    Nota(Cifrado nota, int octava);
    Nota(int id);

    string nombre();
    Nota tercera();
    Nota quinta();
    Nota septima();
    Nota octava();
    Nota sostenido();
    Nota bemol();

    int id();
    double frecuencia();
    double sample(double t, int armonicos);
};

class Acorde
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

    double sample(double t, int armonicos);
    double mejorDuracion(double duracionPedida);
};

typedef struct Envolvente
{
    double tiempoAtaque = 0.1;
    double tiempoDecaer = 0.01;
    double tiempoSoltar = 0.2;

    double nivelSostener = 0.8;
    double nivelAtaque = 1.0;
} Envolvente;

class Evento
{
private:
    Acorde *m_acorde;
    Figura m_figura;

public:
    Evento(Acorde *acorde, Figura figura)
    {
        m_acorde = acorde;
        m_figura = figura;
    }
    Evento(string nombre, Figura figura);

    double duracion(int pulso);
    Acorde *acorde() { return m_acorde; }

    bool esSilencio() { return m_acorde == nullptr; }
};

class Voz
{
private:
    vector<Evento> m_eventos;
    int m_pulso = 60;
    int m_armonicos = 5;
    double m_duracion = 0;
    void actualizarDuracion();

    Envolvente m_envolvente;

public:
    Voz(vector<Evento> eventos);
    vector<Evento> eventos() { return m_eventos; }

    void setearPulso(int pulso);
    void setearArmonicos(int n) { m_armonicos = n; }
    void setearEnvolvente(Envolvente envolvente) { m_envolvente = envolvente; }
    void agregar(Evento evento);
    void agregarEn(Evento evento, int index);

    double samplearEnvolvente(double tiempo, double duracionTotal);
    void producirRaw(string nombre);

    double duracion() { return m_duracion; }
};