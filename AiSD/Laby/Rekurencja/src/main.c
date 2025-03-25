#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_INT	100


int ile(int x, int k) {
	// 331  3
	// 331 % 10 = 1	
	// 33  % 10 = 3
	// 3   % 10 = 3
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		fprintf(stderr, "%s <n>\n", argv[0]);
		return 0;
	}

	int n = atoi(argv[1]);

	srand(time(NULL));

	int numbers[n];
	for (int i = 0; i < n; i++)
		numbers[i] = (double)rand()/RAND_MAX * MAX_INT;


	return 0;
}
