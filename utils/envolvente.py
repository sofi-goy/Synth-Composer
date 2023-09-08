import numpy as np
import matplotlib.pyplot as plt


def samplearEnvolvente(t: float, duracionTotal : float):
    tiempoAtaque = 0.05
    tiempoDecaer = 0.5
    tiempoSoltar = 0.05

    nivelAtaque = 1.0
    nivelSostener = 0.7

    amplitud = 0.0

    def casoIdeal(tiempo):
        if (tiempo < 0):
            return 0

        # Ataque
        elif (tiempo <= tiempoAtaque):
            return (tiempo / tiempoAtaque) * nivelAtaque

        # Decaer
        elif (tiempo <= tiempoAtaque + tiempoDecaer):
            return ((tiempo - tiempoAtaque) / tiempoDecaer) * (nivelSostener - nivelAtaque) + nivelAtaque

        # Sostener
        else:
            return nivelSostener
    
    if t < duracionTotal - tiempoSoltar:
        amplitud = casoIdeal(t)
    else:
        soltar = duracionTotal - tiempoSoltar
        altura = casoIdeal(soltar)
        amplitud = altura * (1 - (t - soltar) / tiempoSoltar)

    return amplitud


duracion = 0.05

x = np.linspace(0,duracion,1000)
y = [samplearEnvolvente(t, duracion) for t in x]

plt.plot(x,y)
plt.show()