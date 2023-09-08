synth: demo.cpp musica.cpp musica.h instrumentos.h efectos.h efectos.cpp
	g++ demo.cpp musica.cpp efectos.cpp -o synth -L wave/ -lwave

debug: demo.cpp musica.cpp musica.h instrumentos.h efectos.h efectos.cpp
	g++ -g demo.cpp musica.cpp efectos.cpp -o synth -L wave/ -lwave
	
run: synth
	./synth && ffplay music.wav