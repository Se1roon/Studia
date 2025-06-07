#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "huffman.h"


int main(int argc, char* argv[]) {
	// ./program [input_file] 
	
	if (argc != 2) {
		printf("Usage: %s [input file]\n", argv[0]);
		return 0;
	}

	char* input_file_path = argv[1];
	FILE* input_file = fopen(input_file_path, "r");
	if (!input_file) {
		fprintf(stderr, "ERROR: File \"%s\" does not exist!\n", input_file_path);
		return -1;
	}
	
	struct stat st;
	stat(input_file_path, &st);
	int input_file_size = st.st_size;

	char* input_buffer = (char*)malloc(input_file_size);
	
	size_t bytes_read = fread(input_buffer, sizeof(char), input_file_size, input_file);


	H_NODE* tree_head = build_huffman_tree(input_buffer, bytes_read);

	print_huffman_tree(tree_head);

	size_t encoded_len = 0;
	unsigned char* encoded = encode(input_buffer, bytes_read, tree_head, &encoded_len);


	printf("Compressed (in binary): %s\n\n", encoded);

	printf("Len of the compressed output (bits) = %zu\n", encoded_len);

	free_huffman_tree(tree_head);

	fclose(input_file);

	return 0;
}

