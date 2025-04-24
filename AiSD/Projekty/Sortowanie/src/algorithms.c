#include <time.h>
#include <stddef.h>
#include <stdio.h>

#include "algorithms.h"


void min_wekt(int *tab, int n, int N, int *i_min, int *min);
void swap(int *a, int *b);
int partition(int *array, int l, int r);
void heapify(int *array, int i, int n);
void shell_sort_insert(int *array, int i_max, int h);


void insertion_sort(int *array, int size) {
	int i, x, j;

	for (i = 2; i <= size; i++) {
		x = array[i];
		j = i - 1;

		array[0] = x;

		while (array[j] > x) {
			array[j + 1] = array[j];
			j--;
		} 

		array[j + 1] = x;
	}

	return;
}

void bubble_sort(int *array, int size) {
	int i, j, pom;
	
	for (j = 0; j < size - 1; j++) {
		for (i = size - 2; i >= j; i--) {
			if (array[i] > array[i + 1]) {
				pom = array[i];
				array[i] = array[i + 1];
				array[i + 1] = pom;
			}
		}
	}

	return;
}

void selection_sort(int *array, int size) {
	int i, pom, j, min;
	for (i = 0; i < size; i++) {
		min_wekt(array, size, i, &j, &min);
		pom = array[i];
		array[i] = min;
		array[j] = pom;
	}

	return;
}

void quicksort_wrapper(int *array, int size) {
	quicksort(array, 0, size - 1);
	return;
}

void quicksort(int *array, int l, int r) {
	if (r <= l) return;
	int i = partition(array, l, r);
	quicksort(array, l, i - 1);
	quicksort(array, i + 1, r);

	return;
}

void heapsort(int *array, int size) {
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(array, i, size);

	for (int i = size - 1; i > 0; i--) {
		swap(&array[0], &array[i]);
		heapify(array, 0, i);
	}
	
	return;
}

void shell_sort(int *array, int size) {
	int hn = 1;
	int h = 1;

	do {
		h = hn;
		hn = h * 3 + 1;
	} while (hn <= size);

	while (h > 0) {
		shell_sort_insert(array, size, h);
		h /= 3;
	}

	return;
}


double get_algo_time(void (*algorithm)(int *, int), int *data, int data_size) {
	clock_t before = clock();
	algorithm(data, data_size);
	clock_t diff = clock() - before;

	return (diff * 1000 / CLOCKS_PER_SEC) / 1000.0;
}


void min_wekt(int *tab, int n, int N, int *i_min, int *min) {
	int i;
	*min = tab[N];
	*i_min = N;
	for (i = N + 1; i < n; i++) {
		if (tab[i] < *min) {
			*min = tab[i];
			*i_min = i;
		}
	}

	return;
}

int partition(int *array, int l, int r) {
	int i = l - 1;
	int j = r;
	int v = array[r];

	for (;;) {
		while (array[++i] < v);
		while (v < array[--j]) 
			if (j == l) break;
		
		if (i >= j) break;
		swap(&array[i], &array[j]);
	}

	swap(&array[i], &array[r]);
	return i;
}

void heapify(int *array, int i, int n) {
	int largest = i;
	int l = 2 * i + 1;
	int r = l + 1;

	if (l < n && array[l] > array[largest]) largest = l;
	if (r < n && array[r] > array[largest]) largest = r;
	if (largest != i) {
		swap(&array[i], &array[largest]);
		heapify(array, largest, n);
	}

	return;
}

void shell_sort_insert(int *array, int i_max, int h) {
	int n, i, j;

	for (n = 0; n < h; n++)
		for (i = n + h; i < i_max; i += h)
			for (j = i - h; j >= 0 && array[j] > array[j + h]; j -= h)
				swap(&array[j + h], &array[j]);

	return;
}

void swap(int *a, int *b) {
	int z = *a;
	*a = *b;
	*b = z;

	return;
}

