#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ile(int x, int k) {
	return (x == 0) ? 0 : (x % 10 == k) + ile(x / 10, k);
}

int zlicz1(int n, int *a, int k) {
	return (n == 0) ? 0 : ile(a[n - 1], k) + zlicz1(n - 1, a, k);
}

int suma_cyfr(int x) {
	return (x < 10) ? x : x % 10 + suma_cyfr(x / 10);
}

int zlicz2(int n, int *a) {
	if (n == 1)
		return suma_cyfr(a[0]);

	int max = zlicz2(n - 1, a);
	int curr = suma_cyfr(a[n - 2]);

	return (curr > max) ? curr : max;
}

int zlicz3(int n, int *a, int i, int max_i) {
	if (i == n) return max_i;
	
	if (suma_cyfr(a[i]) > suma_cyfr(a[max_i]))
		max_i = i;

	return zlicz3(n, a, i + 1, max_i);
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <n> <k>\n", argv[0]);
		return 0;
	}

	int n = atoi(argv[1]);
	int k = atoi(argv[2]);

	int a[n];

	srand(time(NULL));

	for (int i = 0; i < n; i++) 
		a[i] = rand() % 99;

	for (int i = 0; i < n; i++)
		printf("Ilość %d w %d = %d\n", k, a[i], ile(a[i], k));

	printf("\nLiczba wszystkich wystąpień %d w tablicy = %d\n", k, zlicz1(n, a, k));
	printf("Maksymalna syma cyfr = %d\n", zlicz2(n, a));
	printf("Indeks liczby z największą sumą cyfr = %d\n", zlicz3(n, a, 1, 0));

	return 0;
}

