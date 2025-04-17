#include <time.h>
#include <stddef.h>

#include "algorithms.h"


void min_wekt(int *tab, int n, int N, int *i_min, int *min);


// Z jednoczesnym przepychaniem (Sortowanie 1 - strona 4)
void insertion_sort_1(int *array, int size) {
	int i, x, j;

	for (i = 1; i < size; i++) {
		x = array[i];
		j = i - 1;

		while (j >= 0 && array[j] > x) {
			array[j + 1] = array[j];
			j--;
		} 

		array[j + 1] = x;
	}

	return;
}

// Z jednoczesnym przepychaniem i wartownikiem (Sortowanie 1 - strona 5)
void insertion_sort_2(int *array, int size) {
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

// Wstawianie połówkowe (Sortowanie 1 - Strona 14)
void insertion_sort_3(int *array, int size) {
	int i, x, j, l, p, sr;

	for (i = 1; i < size; i++) {
		x = array[i];
		l = 0;
		p = i - 1;

		while (l <= p) {
			sr = (l + p) / 2;
			if (x < array[sr]) p = sr - 1;
			else l = sr + 1;
		}

		for (j = i - 1; j >= l; j--) {
			array[j + 1] = array[j];
			array[l] = x;
		}
		
	}

	return;
}

// Sortowanie 1 - Strona 15
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

// Sortowanie 1 - Strona 23
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

