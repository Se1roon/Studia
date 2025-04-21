#ifndef IO_H
#define IO_H

#include <stdbool.h>


typedef enum insertion_sort_type {
	INS1=1, INS2, INS3, INS4, // INS4 = ALL insertion_sorts
} INSERTION_T;

typedef enum quicksort_type {
	QS1=1, QS2, QS3 // QS3 = All quicksorts
} QUICKSORT_T;

typedef struct options_t {
	char *f_path;   // Path to file containing data
	bool print;		// Print sorted array 
	bool a;         // All
	INSERTION_T is; // Insertion sort
	bool bs;        // Bubble sort
	bool ss;	    // Selection Sort
	QUICKSORT_T qs; // Quicksort
	bool hs;		// Heapsort
	bool shell;     // Shell Sort
} OPTIONS;


void print_help(char *argv[]);
OPTIONS *get_options(int argc, char *argv[]);

int *load_data_file(char *path, int *size_out);


#endif
