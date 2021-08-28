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
    LineaMusical melodia = LineaMusical({});

    Nota nota = Nota(Cifrado::A, 2, Figura::Blanca);
    Acorde* acorde;

    for (int i = 0; i < 8; i++)
    {
        acorde = mayor(nota);
        melodia.agregar(acorde);
        nota = nota.tercera();
    }

    Envolvente env = Envolvente();
    env.tiempoAtaque = 0.1;
    env.tiempoDecaer = 0.02;
    env.tiempoSoltar = 0.2;
    env.nivelSostener = 0.75;
    melodia.setearEnvolvente(env);

    melodia.setearPulso(60);
    melodia.setearArmonicos(10);
    melodia.producirRaw("music.bin");
}