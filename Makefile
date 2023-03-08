all: main
main: ./src/main.c
	gcc -Wall ./src/IntVector.c ./src/main.c -o main