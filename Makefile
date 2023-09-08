synth: demo.cpp musica.cpp musica.h instrumentos.h
	g++ demo.cpp musica.cpp -o synth -L wave/ -lwave

debug: demo.cpp musica.cpp musica.h instrumentos.h
	g++ -g demo.cpp musica.cpp -o synth -L wave/ -lwave
	
run: synth
	./synth && ffplay music.wav