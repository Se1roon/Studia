CFLAGS := -lm -Wall -Wextra


run: build
	./bin/main -f dane -p -a


build: ./src/main.c ./src/io.c ./src/algorithms.c ./inc/io.h ./inc/algorithms.h
	gcc -o ./bin/main ./src/main.c ./src/io.c ./src/algorithms.c -I./inc/ $(CFLAGS)
	./bin/main

build-generator: ./src/data_generator.c
	gcc -o ./bin/gen ./src/data_generator.c $(CFLAGS)
	./bin/gen

