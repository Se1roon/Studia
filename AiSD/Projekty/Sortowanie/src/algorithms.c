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

