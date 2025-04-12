#include <sys/time.h>
#include <stddef.h>

#include "algorithms.h"


void insertion_sort_asc(int *array, int size) {
	for (int i = 1; i < size; i++) {
		int v = array[i];
		int p = i - 1;

		while (p >= 0 && array[p] > v) {
			array[p + 1] = array[p];
			array[p] = v;
			p--;
		}
	}

	return;
}

int get_algo_time(void (*algorithm)(int *, int), int *data, int data_size) {
	struct timeval start, stop;

	gettimeofday(&start, NULL);
	algorithm(data, data_size);
	gettimeofday(&stop, NULL);

	return stop.tv_usec - start.tv_usec;
}

