#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "algorithms.h"
#include "io.h"


int main(int argc, char *argv[]) {
	OPTIONS *options = get_options(argc, argv);
	if (!options) return 0;

	int arr_len = 0;
	int *arr = NULL;	
	if (options->f_path) {
		arr = load_data_file(options->f_path, &arr_len);

		int *arr_copy = (int *)calloc(arr_len, sizeof(int));

		double exec_time = 0.0;
		if (options->is || options->a) {
			memcpy(arr_copy, arr, arr_len * sizeof(int));
			exec_time = get_algo_time(&insertion_sort, arr_copy, arr_len);
			printf("[Insertion Sort] took %.3lf second(s) to execute.\n", exec_time);
			if (options->print) print_array(arr_copy, arr_len);
		}
		if (options->bs || options->a) {
			memcpy(arr_copy, arr, arr_len * sizeof(int));
			exec_time = get_algo_time(&bubble_sort, arr_copy, arr_len);
			printf("[Bubble Sort] took %.3lf second(s) to execute.\n", exec_time);
			if (options->print) print_array(arr_copy, arr_len);
		}
		if (options->ss || options->a) {
			memcpy(arr_copy, arr, arr_len * sizeof(int));
			exec_time = get_algo_time(&selection_sort, arr_copy, arr_len);
			printf("[Selection Sort] took %.3lf second(s) to execute.\n", exec_time);
			if (options->print) print_array(arr_copy, arr_len);
		}
		if (options->qs || options->a) {
			memcpy(arr_copy, arr, arr_len * sizeof(int));
			exec_time = get_algo_time(&quicksort_wrapper, arr_copy, arr_len);
			printf("[Quicksort] took %.3lf second(s) to execute.\n", exec_time);
			if (options->print) print_array(arr_copy, arr_len);
		}
		if (options->hs || options->a) {
			memcpy(arr_copy, arr, arr_len * sizeof(int));
			exec_time = get_algo_time(&heapsort, arr_copy, arr_len);
			printf("[Heapsort] took %.3lf second(s) to execute.\n", exec_time);
			if (options->print) print_array(arr_copy, arr_len);
		}
		if (options->shell || options->a) {
			memcpy(arr_copy, arr, arr_len * sizeof(int));
			exec_time = get_algo_time(&shell_sort, arr_copy, arr_len);
			printf("[Shell Sort] took %.3lf second(s) to execute.\n", exec_time);
			if (options->print) print_array(arr_copy, arr_len);	
		}

		free(arr_copy);
		free(arr);

	} else {
		fprintf(stderr, "Missing input file path!\n");
		print_help(argv);
	}

	free(options);
	return 0;
}

