#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "io.h"


int *generate_data(int size, VARIANT v) {
	int *array = (int *)calloc(size, sizeof(int));
	if (v == RANDOM) {
		srand(time(NULL));

		for (int i = 0; i < size; i++)
			array[i] = (double)rand()/RAND_MAX * 200 - 100;
	}
	else if (v == REVERSE) {
		// For now it generates in descending order
		for (int i = 0; i < size; i++)
			array[i] = size - i;
	}
	else if (v == SORTED) {
		for (int i = 0; i < size; i++)
			array[i] = i;
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

