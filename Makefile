synth: demo.cpp musica.cpp musica.h instrumentos.h
	g++ demo.cpp musica.cpp -o synth -L. -lwave

debug: demo.cpp musica.cpp musica.h instrumentos.h
	g++ -g demo.cpp musica.cpp -o synth -L. -lwave
	
run: synth
	./synth && ffplay -showmode 1 music.wav