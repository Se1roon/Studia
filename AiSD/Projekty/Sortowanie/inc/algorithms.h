#ifndef ALGORITHMS_H
#define ALGORITHMS_H


void insertion_sort(int *array, int size);
void bubble_sort(int *array, int size);
void selection_sort(int *array, int size);
void quicksort_wrapper(int *array, int size);
void quicksort(int *array, int l, int r);
void heapsort(int *array, int size);
void shell_sort(int *array, int size);

double get_algo_time(void (*algorithm)(int *, int), int *data, int data_size);


#endif
