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

int main()
{
    Voz melodia = Voz({});

    Nota nota = Nota(Cifrado::C, 2);
    Acorde *acorde = mayor(nota);
    Evento evento = Evento(acorde, Figura::Negra);

    for (int i = 0; i < 12; i++)
    {
        melodia.agregar(move(evento));
        nota = nota.tercera();
        acorde = mayor(nota);
        evento = Evento(acorde, Figura::Negra);
    }

    Envolvente env = Envolvente();
    env.tiempoAtaque = 0.1;
    env.tiempoDecaer = 0.05;
    env.tiempoSoltar = 0.2;
    env.nivelSostener = 0.7;

    melodia.setearPulso(60);
    melodia.setearArmonicos(6);
    melodia.setearEnvolvente(env);
    melodia.producirRaw("music.bin");
}