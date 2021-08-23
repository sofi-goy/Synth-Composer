synth: main.cpp musica.cpp musica.h
	g++ main.cpp musica.cpp -o synth
	
run:
	./synth && ffplay -f f64le -ar 44100 -showmode 1 music.bin