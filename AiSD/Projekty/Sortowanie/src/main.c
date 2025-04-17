#include <stdio.h>
#include <stdlib.h>

#include "algorithms.h"
#include "io.h"


int main(int argc, char *argv[]) {
	OPTIONS *options = get_options(argc, argv);
	if (!options) return 0;

	int n = options->n;
	int *arr = NULL;	

	if (options->is > 0 || options->a) {
		if (options->is == INS1 || options->is == INS4 || options->a) {
			arr = generate_data(n, options->v);
			double exec_time = get_algo_time(&insertion_sort_1, arr, n);
			printf("[Insertion Sort 1] took %.3lf second(s) to execute.\n\n", exec_time);
			free(arr);
		}
		if (options->is == INS2 || options->is == INS4 || options->a) {
			arr = generate_data(n, options->v);
			double exec_time = get_algo_time(&insertion_sort_2, arr, n);
			printf("[Insertion Sort 2] took %.3lf second(s) to execute.\n\n", exec_time);
			free(arr);
		}
		if (options->is == INS3 || options->is == INS4 || options->a) {
			arr = generate_data(n, options->v);
			double exec_time = get_algo_time(&insertion_sort_3, arr, n);
			printf("[Insertion Sort 3] took %.3lf second(s) to execute.\n\n", exec_time);
			free(arr);
		}
	}

	if (options->bs || options->a) {
		arr = generate_data(n, options->v);
		double exec_time = get_algo_time(&bubble_sort, arr, n);
		printf("[Bubble Sort] took %.3lf second(s) to execute.\n\n", exec_time);
		free(arr);
	}

	if (options->ss || options->a) {
		arr = generate_data(n, options->v);
		double exec_time = get_algo_time(&selection_sort, arr, n);
		printf("[Selection Sort] took %.3lf second(s) to execute.\n\n", exec_time);
		free(arr);	
	}

	//output_data(arr, n);
	free(options);
	return 0;
}

