#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


void print_help(char *argv[]);
void generate_random_data(int n, FILE *file);
void generate_asc_data(int n, FILE *file);
void generate_dsc_data(int n, FILE *file);


int main(int argc, char *argv[]) {
	if (argc != 4) {
		print_help(argv);
		return 0;
	}

	int count = atoi(argv[1]);
	int type = atoi(argv[2]);
	char *path = argv[3];

	FILE *f = fopen(path, "w+");
	if (type == 0)
		generate_random_data(count, f);
	else if (type == 1)
		generate_asc_data(count, f);
	else if (type == 2)
		generate_dsc_data(count, f);
	else {
		fprintf(stderr, "Unknown type of data!\n");
		return -2;
	}

	return 0;
}

void generate_random_data(int n, FILE *file) {
	srand(time(NULL));

	int *arr = (int *)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
		arr[i] = (double)rand()/RAND_MAX * 200 - 100;

	fwrite(arr, sizeof(int), n, file);

	free(arr);
	return;
}

void generate_asc_data(int n, FILE *file) {
	int *arr = (int *)calloc(n, sizeof(int));

	int repeat_num = (int)ceil(n / 200.0);
	int current_num = -100;

	for (int i = 0; i < n; i++) {
		if (i % repeat_num == 0) current_num++;
		arr[i] = current_num;
	}

	fwrite(arr, sizeof(int), n, file);

	free(arr);
	return;
}

void generate_dsc_data(int n, FILE *file) {
	int *arr = (int *)calloc(n, sizeof(int));

	int repeat_num = (int)ceil(n / 200.0);
	int current_num = 100;

	for (int i = 0; i < n; i++) {
		if (i % repeat_num == 0) current_num--;
		arr[i] = current_num;
	}

	fwrite(arr, sizeof(int), n, file);
	
	free(arr);
	return;
}

void print_help(char *argv[]) {
	printf("Usage: %s <number of elements> <order> <out path>\n", argv[0]);
	printf("\t\tOrder:\n\t\t\t0 - random\n");
	printf("\t\t\t1 - sorted ascending\n");
	printf("\t\t\t2 - sorted descending\n");
	return;
}
