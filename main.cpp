#include "musica.h"
#include <iostream>

using namespace std;

Acorde mayor(Nota nota)
{
    return Acorde(nota, false, false, false);
}

Acorde menor(Nota nota)
{
    return Acorde(nota, true, false, false);
}

int main()
{
    Acorde c = mayor(Nota(Cifrado::C, 4));
    Acorde c2 = mayor(Nota(Cifrado::C, 5));
    Acorde sol = mayor(Nota(Cifrado::G, 4));
    Acorde fa = mayor(Nota(Cifrado::F, 4));

    Voz melodia = Voz({});

    for (int i = 0; i < 20; i++)
    {
        melodia.agregar(Evento(&c, Figura::Negra));
        melodia.agregar(Evento(&sol, Figura::Negra));
    }

    melodia.setearPulso(60);
    melodia.producirRaw("music.bin");
}