#include <stdio.h>
#include <stdlib.h>

#include "algorithms.h"
#include "io.h"


int main(int argc, char *argv[]) {
	OPTIONS *options = get_options(argc, argv);
	if (!options) return 0;

	// Maybe implement some kind of summary of the options used

	int n = options->n;

	int *arr = generate_data(n, options->v);

	if (options->i || options->a) {
		double execution_time = get_algo_time(&insertion_sort_asc, arr, n) / 1000.0;
		printf("[Insertion Sort] took %.2lf second(s) to execute.\n\n", execution_time);
	}

	output_data(arr, n);
	free(arr);
	free(options);
	return 0;
}

