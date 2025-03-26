#include <stdio.h>
#include <stdlib.h>

#include "algorithms.h"
#include "io.h"


int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <n>\n", argv[0]);
		return 0;
	}

	int n = atoi(argv[1]);

	int *arr = generate_data(n, RANDOM);
	
	insertion_sort_asc(arr, n);

	for (int i = 0; i < n; i++)
		printf("a[%d] = %d\n", i, arr[i]);

	output_data(arr, n);

	free(arr);
	return 0;
}

