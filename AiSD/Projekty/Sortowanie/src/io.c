#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

#include "io.h"


void print_help(char *argv[]) {
	printf("Usage: %s -f <path> -p [-a|-i|-b|-e|-q|-h|-S]\n\n", argv[0]);
	printf("\t\t-f  -- Sciezka do pliku z danymi\n");
	printf("\t\t-p  -- Wypisuje posortowana tablice\n\n");
	printf("\tALGORYTMY\n");
	printf("\t\t-a  -- Wszystkie algorytmy na raz\n");
	printf("\t\t-i  -- Sortowanie przez wybieranie\n");
	printf("\t\t-b  -- Bubble sort\n");
	printf("\t\t-e  -- Selection sort\n");
	printf("\t\t-q  -- Quicksort\n");
	printf("\t\t-h  -- Heapsort\n");
	printf("\t\t-S  -- Shell Sort\n\n");
	
	return;
}

// A lot of errors might happen here (mallocs, atois, etc.)
OPTIONS *get_options(int argc, char *argv[]) {
	if (argc == 1) {
		print_help(argv);
		return NULL;
	}

	OPTIONS *opts = (OPTIONS *)calloc(1, sizeof(OPTIONS)); 
	opts->f_path = NULL;

	int c;
	while ((c = getopt(argc, argv, "f:paibeqhS")) > 0) {
		switch (c) {
			case 'f':
				opts->f_path = optarg;
				break;
			case 'p':
				opts->print = true;
				break;
			case 'a':
				opts->a = true;
				break;
			case 'i':
				opts->is = true;	
				break;
			case 'b':
				opts->bs = true;
				break;
			case 'e':
				opts->ss = true;
				break;
			case 'q':
				opts->qs = true;
				break;
			case 'h':
				opts->hs = true;
				break;
			case 'S':
				opts->shell = true;
				break;
			case '?':
				print_help(argv);
				free(opts);
				exit(0);
		}
	}

	return opts;
}

int *load_data_file(char *path, int *size_out) {
	FILE *in_f = fopen(path, "r+");
	if (!in_f) {
		fprintf(stderr, "\"%s\" doesn't exist!\n", path);
		exit(-1);
	}

	int arr_len = 1;
	int *arr = (int *)calloc(arr_len, sizeof(int));

	while (fread(&arr[arr_len - 1], sizeof(int), 1, in_f) > 0)
		arr = (int *)realloc(arr, sizeof(int) * (++arr_len));
	arr = (int *)realloc(arr, sizeof(int) * (--arr_len));

	*size_out = arr_len;
	return arr;
}

void print_array(int *array, int array_len) {
	printf("Sorted array: ");
	for (int i = 0; i < array_len; i++) {
		if (i == array_len - 1) printf("%d\n", array[i]);
		else printf("%d, ", array[i]);
	}
	printf("\n");

	return;
}

