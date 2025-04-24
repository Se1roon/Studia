#ifndef IO_H
#define IO_H

#include <stdbool.h>


typedef struct options_t {
	char *f_path;   // Path to file containing data
	bool print;		// Print sorted array 
	bool a;         // All
	bool is;		// Insertion sort
	bool bs;        // Bubble sort
	bool ss;	    // Selection Sort
	bool qs;		// Quicksort
	bool hs;		// Heapsort
	bool shell;     // Shell Sort
} OPTIONS;


void print_help(char *argv[]);
OPTIONS *get_options(int argc, char *argv[]);

int *load_data_file(char *path, int *size_out);
void print_array(int *array, int array_len);


#endif
