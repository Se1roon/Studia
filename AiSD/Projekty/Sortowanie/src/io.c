#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

#include "io.h"


void print_help(char *argv[]) {
	printf("Usage: %s -n [-a|-i] [-r|-d|-s]\n\n", argv[0]);
	printf("\t\t-n  -- Ilosc elementow\n\n");
	printf("\tALGORYTMY (jedna opcja)\n");
	printf("\t\t-a  -- Wszystkie algorytmy na raz\n");
	printf("\t\t-i  -- Sortowanie przez wybieranie\n\n");
	printf("\tDANE (jedna opcja, domyslnie -r)\n");
	printf("\t\t-r  -- Losowe liczby calkowite\n");
	printf("\t\t-d  -- Liczby w kolejnosc malejacej\n");
	printf("\t\t-s  -- Posortowane liczby\n\n");
	
	return;
}

// A lot of errors might happen here (mallocs, atois, etc.)
OPTIONS *get_options(int argc, char *argv[]) {
	if (argc == 1) {
		print_help(argv);
		return NULL;
	}

	OPTIONS *opts = (OPTIONS *)calloc(1, sizeof(OPTIONS)); // Using calloc so that bools are init to false

	int c;
	while ((c = getopt(argc, argv, "n:airds")) > 0) {
		switch (c) {
			case 'n':
				opts->n = atoi(optarg);
				break;
			case 'a':
				opts->a = true;
				break;
			case 'i':
				if (opts->a) {
					fprintf(stderr, "Prosze o podanie tylko jednej sposrod flag: -a, -i\n");
					print_help(argv);
					exit(0);
				} else opts->i = true;
				break;
			case 'r':
				opts->v = RANDOM;
				break;
			case 'd':
				opts->v = REVERSE;
				break;
			case 's':
				opts->v = SORTED;
				break;
			case '?':
				print_help(argv);
				exit(0);
		}
	}

	return opts;
}

int *generate_data(int size, VARIANT v) {
	int *array = (int *)calloc(size, sizeof(int));

	if (v == RANDOM) {
		srand(time(NULL));

		for (int i = 0; i < size; i++)
			array[i] = (double)rand()/RAND_MAX * 200 - 100;
	}
	else if (v == REVERSE) {
		int repeat_num = (int)ceil(size / 200.0);
		int current_num = 100;

		for (int i = 0; i < size; i++) {
			if (i % repeat_num == 0) current_num--;
			array[i] = current_num;
		}
	}
	else if (v == SORTED) {
		int repeat_num = (int)ceil(size / 200.0);
		int current_num = -100;

		for (int i = 0; i < size; i++) {
			if (i % repeat_num == 0) current_num++;
			array[i] = current_num;
		}
	}

	return array;
}

int *read_data(int size) {
	// ??? Nie wiem czy to w ogole potrzebne przeczytac jeszcze raz pdfa
	FILE *file = fopen("./dane", "r+");
	if (!file) {
		fprintf(stderr, "Plik 'dane' nie istnieje!\n");
		return NULL;
	}

	int *array = (int *)calloc(size, sizeof(int));
	fread(array, sizeof(int), size, file);

	return array;
}

void output_data(int *array, int size) {
	// Maybe delete size parameter and somehow deduce array size
	FILE *file = fopen("./dane", "w+");
	fwrite(array, sizeof(int), size, file);

	fclose(file);

	return;
}

