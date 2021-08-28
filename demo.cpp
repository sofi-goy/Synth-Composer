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

vector<Evento*> pruebaTerceras()
{
    vector<Evento*> melodia {};

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

vector<Evento*> pruebaBach()
{
    vector<Evento*> melodia {};

    melodia.push_back(new Nota(Cifrado::D, 4, Figura::Negra));
    melodia.push_back(new Nota(Cifrado::G, 3, Figura::Corchea));
    melodia.push_back(new Nota(Cifrado::A, 3, Figura::Corchea));
    melodia.push_back(new Nota(Cifrado::B, 3, Figura::Corchea));
    melodia.push_back(new Nota(Cifrado::C, 4, Figura::Corchea));
    melodia.push_back(new Nota(Cifrado::D, 4, Figura::Negra));
    melodia.push_back(new Nota(Cifrado::G, 3, Figura::Negra));
    melodia.push_back(new Nota(Cifrado::G, 3, Figura::Negra));

    melodia.push_back(new Nota(Cifrado::E, 4, Figura::Negra));
    melodia.push_back(new Nota(Cifrado::C, 4, Figura::Corchea));
    melodia.push_back(new Nota(Cifrado::D, 4, Figura::Corchea));
    melodia.push_back(new Nota(Cifrado::E, 4, Figura::Corchea));
    melodia.push_back(new Nota(Cifrado::FS, 4, Figura::Corchea));
    melodia.push_back(new Nota(Cifrado::G, 4, Figura::Negra));
    melodia.push_back(new Nota(Cifrado::G, 3, Figura::Negra));
    melodia.push_back(new Nota(Cifrado::G, 3, Figura::Negra));

    return melodia;
}

int main()
{
    auto melodia = pruebaBach();
    Harmonica principal {melodia};
    
    principal.setearPulso(60);
    principal.producirRaw("music.bin");
}