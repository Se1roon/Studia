#include <stdio.h>

void swap(int *a, int *b) {
	int z = *a;
	*a = *b;
	*b = z;
}

int partition(int a[], int l, int r) {
	int i = l - 1, j, v = a[r];

	for (j = l; j < r; j++)
		if (a[j] <= v) {
			i++;
			swap(&a[i], &a[j]);
			printf("Swap 1\n");
		}
	swap(&a[i + 1], &a[r]);
	printf("Swap 2\n");

	return i + 1;
}

void quicksort(int a[], int l, int r) {
	if (r <= l) return;
	int i = partition(a, l, r);
	quicksort(a, l, i - 1);
	quicksort(a, i + 1, r);
}

int main(void) {
	int a[7] = { 3, 9, 5, 1, 4, 3, 1};

	quicksort(a, 0, 6);

	for (int i = 0; i < 7; i++)
		printf("%d ", a[i]);

	return 0;
}
