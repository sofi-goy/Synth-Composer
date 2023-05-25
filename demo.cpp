#include "musica.h"
#include "instrumentos.h"
#include <iostream>

using namespace std;

Acorde *mayor(Nota nota)
{
    return new Acorde(nota, false, false, false);
}

Acorde *menor(Nota nota)
{
    return new Acorde(nota, true, false, false);
}

vector<Evento *> pruebaTerceras()
{
    vector<Evento *> melodia{};

    Nota nota = Nota(Cifrado::C, 2, Figura::Blanca);
    Acorde *acorde;

    for (int i = 0; i < 8; i++)
    {
        acorde = menor(nota);
        melodia.push_back(acorde);
        nota = nota.tercera();
    }

    return melodia;
}

vector<Evento *> pruebaBach()
{
    return {
        new Nota(Cifrado::D, 4, Figura::Negra),
        new Nota(Cifrado::G, 3, Figura::Corchea),
        new Nota(Cifrado::A, 3, Figura::Corchea),
        new Nota(Cifrado::B, 3, Figura::Corchea),
        new Nota(Cifrado::C, 4, Figura::Corchea),
        new Nota(Cifrado::D, 4, Figura::Negra),
        new Nota(Cifrado::G, 3, Figura::Negra),
        new Nota(Cifrado::G, 3, Figura::Negra),
        new Nota(Cifrado::E, 4, Figura::Negra),
        new Nota(Cifrado::C, 4, Figura::Corchea),
        new Nota(Cifrado::D, 4, Figura::Corchea),
        new Nota(Cifrado::E, 4, Figura::Corchea),
        new Nota(Cifrado::FS, 4, Figura::Corchea),
        new Nota(Cifrado::G, 4, Figura::Negra),
        new Nota(Cifrado::G, 3, Figura::Negra),
        new Nota(Cifrado::G, 3, Figura::Negra),
        new Nota(Cifrado::C, 4, Figura::Negra),
        new Nota(Cifrado::D, 4, Figura::Corchea),
        new Nota(Cifrado::C, 4, Figura::Corchea),
        new Nota(Cifrado::B, 3, Figura::Corchea),
        new Nota(Cifrado::A, 3, Figura::Corchea),
        new Nota(Cifrado::B, 3, Figura::Negra),
        new Nota(Cifrado::C, 4, Figura::Corchea),
        new Nota(Cifrado::B, 3, Figura::Corchea),
        new Nota(Cifrado::A, 3, Figura::Corchea),
        new Nota(Cifrado::G, 3, Figura::Corchea),
        new Nota(Cifrado::FS, 3, Figura::Negra),
        new Nota(Cifrado::G, 3, Figura::Corchea),
        new Nota(Cifrado::A, 3, Figura::Corchea),
        new Nota(Cifrado::B, 3, Figura::Corchea),
        new Nota(Cifrado::G, 3, Figura::Corchea),
        new Nota(Cifrado::A, 3, Figura::Blanca),
        new Nota(Cifrado::A, 3, Figura::Negra),
        new Nota(Cifrado::D, 4, Figura::Negra),
        new Nota(Cifrado::G, 3, Figura::Corchea),
        new Nota(Cifrado::A, 3, Figura::Corchea),
        new Nota(Cifrado::B, 3, Figura::Corchea),
        new Nota(Cifrado::C, 4, Figura::Corchea),
        new Nota(Cifrado::D, 4, Figura::Negra),
        new Nota(Cifrado::G, 3, Figura::Negra),
        new Nota(Cifrado::G, 3, Figura::Negra),
        new Nota(Cifrado::E, 4, Figura::Negra),
        new Nota(Cifrado::C, 4, Figura::Corchea),
        new Nota(Cifrado::D, 4, Figura::Corchea),
        new Nota(Cifrado::E, 4, Figura::Corchea),
        new Nota(Cifrado::FS, 4, Figura::Corchea),
        new Nota(Cifrado::G, 4, Figura::Negra),
        new Nota(Cifrado::G, 3, Figura::Negra),
        new Nota(Cifrado::G, 3, Figura::Negra),
        new Nota(Cifrado::C, 4, Figura::Negra),
        new Nota(Cifrado::D, 4, Figura::Corchea),
        new Nota(Cifrado::C, 4, Figura::Corchea),
        new Nota(Cifrado::B, 3, Figura::Corchea),
        new Nota(Cifrado::A, 3, Figura::Corchea),
        new Nota(Cifrado::B, 3, Figura::Negra),
        new Nota(Cifrado::C, 4, Figura::Corchea),
        new Nota(Cifrado::B, 3, Figura::Corchea),
        new Nota(Cifrado::A, 3, Figura::Corchea),
        new Nota(Cifrado::G, 3, Figura::Corchea),
        new Nota(Cifrado::A, 3, Figura::Negra),
        new Nota(Cifrado::B, 3, Figura::Corchea),
        new Nota(Cifrado::A, 3, Figura::Corchea),
        new Nota(Cifrado::G, 3, Figura::Corchea),
        new Nota(Cifrado::FS, 3, Figura::Corchea),
        new Nota(Cifrado::G, 3, Figura::Blanca),
        new Nota(Cifrado::G, 3, Figura::Negra)};
}

vector<Evento *> pruebaAcordes()
{
    vector<Evento *> linea {};
    
    auto acorde = new Acorde(Nota(Cifrado::C, 2, Figura::Blanca));
    auto silencio = new Silencio(Figura::Blanca);

    for (int i = 0; i < 6; i++)
        linea.push_back(acorde);
        linea.push_back(silencio);

    return linea;
}

vector<Evento *> megalovania()
{
    return {
        new Nota(Cifrado::D, 4, Figura::Semicorchea),
        new Nota(Cifrado::D, 4, Figura::Semicorchea),
        new Nota(Cifrado::D, 5, Figura::Corchea),
        new Nota(Cifrado::A, 4, Figura::Corchea),
        new Silencio(Figura::Semicorchea),
        new Nota(Cifrado::GS, 4, Figura::Semicorchea),
        new Silencio(Figura::Semicorchea),
        new Nota(Cifrado::G, 4, Figura::Semicorchea),
        new Silencio(Figura::Semicorchea),
        new Nota(Cifrado::F, 4, Figura::Corchea),
        new Nota(Cifrado::D, 4, Figura::Semicorchea),
        new Nota(Cifrado::F, 4, Figura::Semicorchea),
        new Nota(Cifrado::G, 4, Figura::Semicorchea),

        new Nota(Cifrado::C, 4, Figura::Semicorchea),
        new Nota(Cifrado::C, 4, Figura::Semicorchea),
        new Nota(Cifrado::D, 5, Figura::Corchea),
        new Nota(Cifrado::A, 4, Figura::Corchea),
        new Silencio(Figura::Semicorchea),
        new Nota(Cifrado::GS, 4, Figura::Semicorchea),
        new Silencio(Figura::Semicorchea),
        new Nota(Cifrado::G, 4, Figura::Semicorchea),
        new Silencio(Figura::Semicorchea),
        new Nota(Cifrado::F, 4, Figura::Corchea),
        new Nota(Cifrado::D, 4, Figura::Semicorchea),
        new Nota(Cifrado::F, 4, Figura::Semicorchea),
        new Nota(Cifrado::G, 4, Figura::Semicorchea),

        new Nota(Cifrado::B, 3, Figura::Semicorchea),
        new Nota(Cifrado::B, 3, Figura::Semicorchea),
        new Nota(Cifrado::D, 5, Figura::Corchea),
        new Nota(Cifrado::A, 4, Figura::Corchea),
        new Silencio(Figura::Semicorchea),
        new Nota(Cifrado::GS, 4, Figura::Semicorchea),
        new Silencio(Figura::Semicorchea),
        new Nota(Cifrado::G, 4, Figura::Semicorchea),
        new Silencio(Figura::Semicorchea),
        new Nota(Cifrado::F, 4, Figura::Corchea),
        new Nota(Cifrado::D, 4, Figura::Semicorchea),
        new Nota(Cifrado::F, 4, Figura::Semicorchea),
        new Nota(Cifrado::G, 4, Figura::Semicorchea),

        new Nota(Cifrado::AS, 3, Figura::Semicorchea),
        new Nota(Cifrado::AS, 3, Figura::Semicorchea),
        new Nota(Cifrado::D, 5, Figura::Corchea),
        new Nota(Cifrado::A, 4, Figura::Corchea),
        new Silencio(Figura::Semicorchea),
        new Nota(Cifrado::GS, 4, Figura::Semicorchea),
        new Silencio(Figura::Semicorchea),
        new Nota(Cifrado::G, 4, Figura::Semicorchea),
        new Silencio(Figura::Semicorchea),
        new Nota(Cifrado::F, 4, Figura::Corchea),
        new Nota(Cifrado::D, 4, Figura::Semicorchea),
        new Nota(Cifrado::F, 4, Figura::Semicorchea),
        new Nota(Cifrado::G, 4, Figura::Semicorchea)
    };
}

vector<Evento*> amelie_izq() {
    vector<Evento*> vuelta {
        new Octava(Nota(Cifrado::E, 3, Figura::Corchea)),
        new Nota(Cifrado::B, 4, Figura::Corchea),
        new Power(Nota(Cifrado::G, 3, Figura::Corchea)),
        new Nota(Cifrado::B, 4, Figura::Corchea),
        new Octava(Nota(Cifrado::E, 3, Figura::Corchea)),
        new Nota(Cifrado::B, 4, Figura::Corchea),
        new Power(Nota(Cifrado::G, 3, Figura::Corchea)),
        new Nota(Cifrado::B, 4, Figura::Corchea),

        new Octava(Nota(Cifrado::D, 3, Figura::Corchea)),
        new Nota(Cifrado::B, 4, Figura::Corchea),
        new Power(Nota(Cifrado::G, 3, Figura::Corchea)),
        new Nota(Cifrado::B, 4, Figura::Corchea),
        new Octava(Nota(Cifrado::D, 3, Figura::Corchea)),
        new Nota(Cifrado::B, 4, Figura::Corchea),
        new Power(Nota(Cifrado::G, 3, Figura::Corchea)),
        new Nota(Cifrado::B, 4, Figura::Corchea),

        new Octava(Nota(Cifrado::D, 3, Figura::Corchea)),
        new Nota(Cifrado::B, 4, Figura::Corchea),
        new Power(Nota(Cifrado::FS, 3, Figura::Corchea)),
        new Nota(Cifrado::B, 4, Figura::Corchea),
        new Octava(Nota(Cifrado::D, 3, Figura::Corchea)),
        new Nota(Cifrado::B, 4, Figura::Corchea),
        new Power(Nota(Cifrado::FS, 3, Figura::Corchea)),
        new Nota(Cifrado::B, 4, Figura::Corchea),

        new Octava(Nota(Cifrado::D, 3, Figura::Corchea)),
        new Nota(Cifrado::B, 4, Figura::Corchea),
        new Power(Nota(Cifrado::FS, 3, Figura::Corchea)),
        new Nota(Cifrado::B, 4, Figura::Corchea),
        new Octava(Nota(Cifrado::D, 3, Figura::Corchea)),
        new Nota(Cifrado::B, 4, Figura::Corchea),
        new Power(Nota(Cifrado::FS, 3, Figura::Corchea)),
        new Nota(Cifrado::B, 4, Figura::Corchea),
    };

    vector<Evento*> melodia;
    melodia.reserve(vuelta.size() * 4);
    for (int i = 0; i < 4; i++) {
        melodia.insert(melodia.end(), vuelta.begin(), vuelta.end());
    }

    return melodia;
}

int main()
{
    Tecladito melodia { amelie_izq() };
    melodia.setearPulso(120);

    Cancion cancion {{melodia}};
    // cancion.producirRaw("music.bin");
    cancion.producirWave("music.wav");
}