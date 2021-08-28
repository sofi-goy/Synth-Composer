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

    Nota nota = Nota(Cifrado::C, 2, Figura::Blanca);
    Acorde* acorde;

    for (int i = 0; i < 8; i++)
    {
        acorde = menor(nota);
        melodia.agregar(acorde);
        nota = nota.tercera();
    }

    Envolvente env = Envolvente();
    env.tiempoAtaque = 0.2;
    env.tiempoDecaer = 0.05;
    env.tiempoSoltar = 0.25;
    env.nivelSostener = 0.75;
    melodia.setearEnvolvente(env);

    melodia.setearArmonicos({1.0/4,1.0/2,1.0/4});
    melodia.setearPulso(60);
    melodia.producirRaw("music.bin");
}