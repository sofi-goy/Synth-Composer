#include "musica.h"
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

LineaMusical pruebaTerceras()
{
    LineaMusical melodia = LineaMusical({});

    Nota nota = Nota(Cifrado::C, 2, Figura::Blanca);
    Acorde *acorde;

    for (int i = 0; i < 8; i++)
    {
        acorde = menor(nota);
        melodia.agregar(acorde);
        nota = nota.tercera();
    }

    return melodia;
}

LineaMusical pruebaBach()
{
    LineaMusical melodia = LineaMusical({});

    melodia.agregar(new Nota(Cifrado::D, 4, Figura::Negra));
    melodia.agregar(new Nota(Cifrado::G, 3, Figura::Corchea));
    melodia.agregar(new Nota(Cifrado::A, 3, Figura::Corchea));
    melodia.agregar(new Nota(Cifrado::B, 3, Figura::Corchea));
    melodia.agregar(new Nota(Cifrado::C, 4, Figura::Corchea));
    melodia.agregar(new Nota(Cifrado::D, 4, Figura::Negra));
    melodia.agregar(new Nota(Cifrado::G, 3, Figura::Negra));
    melodia.agregar(new Nota(Cifrado::G, 3, Figura::Negra));

    melodia.agregar(new Nota(Cifrado::E, 4, Figura::Negra));
    melodia.agregar(new Nota(Cifrado::C, 4, Figura::Corchea));
    melodia.agregar(new Nota(Cifrado::D, 4, Figura::Corchea));
    melodia.agregar(new Nota(Cifrado::E, 4, Figura::Corchea));
    melodia.agregar(new Nota(Cifrado::FS, 4, Figura::Corchea));
    melodia.agregar(new Nota(Cifrado::G, 4, Figura::Negra));
    melodia.agregar(new Nota(Cifrado::G, 3, Figura::Negra));
    melodia.agregar(new Nota(Cifrado::G, 3, Figura::Negra));

    return melodia;
}

int main()
{
    auto melodia = pruebaBach();

    Envolvente env = Envolvente();
    env.tiempoAtaque = 0.1;
    env.tiempoDecaer = 0.1;
    env.tiempoSoltar = 0.2;
    env.nivelSostener = 0.5;
    melodia.setearEnvolvente(env);

    melodia.setearArmonicos({1.0 / 2, 1.0 / 4, 1.0 / 4});
    melodia.setearPulso(90);
    melodia.setearOnda(Onda::CUADRADA);
    melodia.producirRaw("music.bin");
}