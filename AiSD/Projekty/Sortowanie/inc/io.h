#ifndef IO_H
#define IO_H

#include <stdbool.h>


typedef enum data_generation_variant {
	RANDOM, REVERSE, SORTED
} VARIANT;

typedef enum insertion_sort_type {
	INS1, INS2, INS3, INS4, // INS4 = ALL insertion_sorts
} INSERTION_T;

typedef struct options_t {
	int n;
	bool a;         // All
	INSERTION_T is; // Insertion sort
	bool bs;        // Bubble sort
	bool ss;	    // Selection Sort
	VARIANT v;  // Dataset
} OPTIONS;


void print_help(char *argv[]);
OPTIONS *get_options(int argc, char *argv[]);

int *generate_data(int size, VARIANT v);
int *read_data(int size); // This can be used to read part of an input from file
void output_data(int *array, int size);


#endif

