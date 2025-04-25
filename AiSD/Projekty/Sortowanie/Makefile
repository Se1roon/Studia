CFLAGS := -lm -Wall -Wextra


run: build
	./main -f dane -p -a


build: ./src/main.c ./src/io.c ./src/algorithms.c ./inc/io.h ./inc/algorithms.h
	gcc -o ./main ./src/main.c ./src/io.c ./src/algorithms.c -I./inc/ $(CFLAGS)
	./main

build-generator: ./src/data_generator.c
	gcc -o ./gen ./src/data_generator.c $(CFLAGS)
	./gen

