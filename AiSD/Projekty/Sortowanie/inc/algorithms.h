#ifndef ALGORITHMS_H
#define ALGORITHMS_H


void insertion_sort_1(int *array, int size);
void insertion_sort_2(int *array, int size);
void insertion_sort_3(int *array, int size);

void bubble_sort(int *array, int size);
void selection_sort(int *array, int size);

double get_algo_time(void (*algorithm)(int *, int), int *data, int data_size);


#endif
