All: compile run
compile:
	gcc -I ./include/ -o ./lib/File.o -c ./src/File.c
	gcc -I ./include/ -o ./lib/Person.o -c ./src/Person.c
	gcc -I ./include/ -o ./lib/Game.o -c ./src/Game.c
	gcc -I ./include/ -o ./bin/Main ./lib/File.o ./lib/Person.o ./lib/Game.o ./src/Main.c
run:
	./bin/Main
