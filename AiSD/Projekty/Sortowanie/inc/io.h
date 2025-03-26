#ifndef IO_H
#define IO_H


typedef enum data_generation_variant {
	RANDOM, REVERSE, SORTED
} VARIANT;

int *generate_data(int size, VARIANT v);
int *read_data(int size); // This can be used to read part of an input from file
void output_data(int *array, int size);


#endif
