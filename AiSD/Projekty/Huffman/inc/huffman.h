#ifndef HUFFMAN_C
#define HUFFMAN_C

#include <stdio.h>
#include <stdbool.h>


typedef struct huffman_node {
	int freq;
	unsigned char element;
	struct huffman_node* left;
	struct huffman_node* right;
} H_NODE;

typedef struct huffman_codes_dict_element {
	unsigned char element;
	char* code;
} H_DICT_ELEM;


H_NODE** get_frequencies(unsigned char* input, size_t input_len, int *out_len);
H_NODE* build_huffman_tree(unsigned char* input, size_t input_len);

char* encode(unsigned char* input, size_t input_len, H_NODE* tree_head, size_t *);

void print_huffman_tree(H_NODE* head);
void free_huffman_tree(H_NODE* head);


#endif

