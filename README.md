# Synth Composer

Esta es una pequeña librería para poder generar archivos de audio a partir
de simples instrucciones, similares a componer una partitura. Por ejemplo:
tocar el acorde `Am` durante dos tiempos.

Además, las líneas melódicas/armónicas pueden ser tocadas por distintos instrumentos 
virtuales, los cuales se pueden configurar. Algunos parámetros que se pueden controlar son:

- El timbre, mediante el uso de distintos armónicos
- La envolvente, que regula la modulación de volumen mientras se toca una nota

## Instrucciones

En el archivo `demo.cpp` se encuentra una pequeña muestra de lo que se puede hacer. 
Para probarlo (en Linux), hay que ejecutar el comando

 ```
 make synth && make run
 ```

 Notar que, para que funcione, la utilidad `ffplay` debe estar instalada en el sistema.

 ## TODO

- Implementar instrumentos básicos (piano, sinte, percusión, guitarra, bajo, cuerdas, saxo)
    Para esto se pueden estudiar samples de instrumentos reales con espectrogramas y cosas.
- ~~Usar distintos tipos de ondas (cuadradas, triangulares, serrucho) para emular consolas retro~~
- Implementar ruido, capaz con Perlin?
- ~~Permitir mayor personalización de los armónicos~~
- ~~Producir audios en formato WAV~~
- Leer formato WAV, y permitir samplear grabaciones
- Implementar LUFS (Loudness Units Full Scale) para normalizar el volumen
- Aplicar un suavizado a la señal para evitar chasquidos
- Implementar efectos de sonido (reverb, delay, chorus, flanger, phaser, etc)