synth: demo.cpp musica.cpp musica.h instrumentos.h
	g++ demo.cpp musica.cpp -o synth

debug: demo.cpp musica.cpp musica.h instrumentos.h
	g++ -g demo.cpp musica.cpp -o synth
	
run:
	./synth && ffplay -f f64le -ar 44100 -showmode 1 music.bin