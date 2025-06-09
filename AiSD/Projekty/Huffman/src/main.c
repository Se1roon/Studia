#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

#include "huffman.h"


int main(int argc, char* argv[]) {
	// ./program [input_file] 
	
	if (argc < 2) {
		printf("Usage: %s [input file] [d]\n", argv[0]);
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

	fclose(input_file);

	H_NODE* tree_head = build_huffman_tree(input_buffer, bytes_read);

	print_huffman_tree(tree_head);

	size_t encoded_len = 0;
	unsigned char* encoded = encode(input_buffer, bytes_read, tree_head, &encoded_len);

	if (argc == 3 && strncmp(argv[2], "d", 1) == 0) {
		int decoded_len = 0;
		char* decoded = decode(encoded, tree_head, &decoded_len);
		printf("\nOriginal: %s\n", decoded);
		free(decoded);
	}

	FILE* output_file = fopen("out_compressed.out", "w+");

	output_to_file(encoded, output_file);

	fclose(output_file);

	printf("\nSize of the compressed output (bits) = %zu\n", encoded_len);

	free_huffman_tree(tree_head);

	return 0;
}

