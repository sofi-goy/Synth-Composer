#include "musica.h"
#include <iostream>

using namespace std;

Acorde* mayor(Nota nota)
{
    return new Acorde(nota, false, false, false);
}

Acorde* menor(Nota nota)
{
    return new Acorde(nota, true, false, false);
}

int main()
{
    Voz melodia = Voz({});

    Nota nota = Nota(Cifrado::C, 2);
    Acorde* acorde = mayor(nota);
    Evento evento = Evento(acorde, Figura::Blanca);

    for (int i = 0; i < 6; i++)
    {
        melodia.agregar(move(evento));
        nota = nota.quinta();
        acorde = mayor(nota);
        evento = Evento(acorde, Figura::Blanca);
    }

    Envolvente env = Envolvente();
    env.tiempoAtaque = 0.02;
    env.tiempoDecaer = 0.02;
    env.tiempoSoltar = 0.04;
    env.nivelSostener = 0.7;

    melodia.setearPulso(60);
    melodia.setearArmonicos(6);
    melodia.setearEnvolvente(env);
    melodia.producirRaw("music.bin");
}