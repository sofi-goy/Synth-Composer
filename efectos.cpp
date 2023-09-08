#include <vector>

using namespace std;

vector<float> suavizar(vector<float> samples, int ventana)
{
    int tamaño = samples.size() - ventana + 1;
    vector<float> suavizado(tamaño);

    float acumulado = 0;
    for (int i = 0; i < ventana; i++)
    {
        acumulado += samples[i];
    }
    for (int i = 0; i < tamaño; i++)
    {
        suavizado[i] = acumulado / ventana;
        acumulado -= samples[i];
        acumulado += samples[i + ventana];
    }

    return suavizado;
}