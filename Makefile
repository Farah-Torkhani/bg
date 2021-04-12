lunatics:main.o bg.o input.o
	gcc main.o bg.o input.o -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -o lunatics -g; ./lunatics
main.o:main.c
	gcc -c main.c -g
bg.o:bg.c
	gcc -c bg.c -g
input.o:input.c
	gcc -c input.c -g


