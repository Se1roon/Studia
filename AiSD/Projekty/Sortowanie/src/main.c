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

	if (options->i || options->a)
		insertion_sort_asc(arr, n);

	for (int i = 0; i < n; i++)
		printf("a[%d] = %d\n", i, arr[i]);

	output_data(arr, n);
	free(arr);
	free(options);
	return 0;
}

