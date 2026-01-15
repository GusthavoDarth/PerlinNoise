
noise:
	gcc -o Noise.exe Noise.c -I include -L lib -lraylib -lgdi32 -lwinmm

perlin:
	gcc -o Perlin.exe Perlin.c -I include -L lib -lraylib -lgdi32 -lwinmm