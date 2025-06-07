#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "huffman.h"


// ================UTILITY DECL================

int _entry_exists(unsigned char, H_NODE** array, int array_len);
int _get_node_index(H_NODE* node, H_NODE** nodes, int nodes_len);

H_DICT_ELEM* _get_dict(unsigned char* input, size_t input_len, H_NODE* head, int *);
unsigned char* _search_dict(unsigned char e, H_DICT_ELEM* dict, int dict_len);
bool _is_in_dict(unsigned char e, H_DICT_ELEM* dict, int dict_len);

unsigned char* _get_code(unsigned char element, H_NODE* tree_head);
bool _get_code_rec(unsigned char e, H_NODE* current, unsigned char* current_code);

void _get_two_least_frequent(H_NODE** nodes, int nodes_len, H_NODE** out_first, H_NODE** out_second);
void _print_huffman_tree(const H_NODE* node, int indentation);

unsigned char* _str_concat(unsigned char** dest, unsigned char* src);

// ============================================

char* encode(unsigned char* input, size_t input_len, H_NODE* tree_head, size_t *out_len) {
	int dict_len = 0;
	H_DICT_ELEM* dict = _get_dict(input, input_len, tree_head, &dict_len);

	unsigned char* output = (unsigned char*)calloc(1, sizeof(char));
	size_t out_used = 0;

	for (size_t i = 0; i < input_len; i++) {
		unsigned char* code = _search_dict(input[i], dict, dict_len);
		size_t code_len = strlen((char*)code);

		char* tmp = realloc(output, out_used + code_len + 1);
		if (!tmp) {
			printf("Malloc failed!\n");
			free(output);
			return NULL;
		}
		output = tmp;
		
		memcpy(output + out_used, code, code_len);
		out_used += code_len;
		output[out_used] = '\0';
	}

	*out_len = strlen(output);

	return output;
}

H_NODE* build_huffman_tree(unsigned char* input, size_t input_len) {
	int nodes_len = 0;
	H_NODE** nodes = get_frequencies(input, input_len, &nodes_len);

	while (nodes_len > 1) {
		// Least frequent nodes
		H_NODE* x = NULL;
		H_NODE* y = NULL;

		_get_two_least_frequent(nodes, nodes_len, &x, &y);

		// Create a new, combined node
		H_NODE* new_node = (H_NODE*)malloc(sizeof(H_NODE));
		new_node->element = 0xff;
		new_node->freq = x->freq + y->freq;
		new_node->left = x;
		new_node->right = y;

		// Replace 2 lightest nodes with the new node
		int x_index = _get_node_index(x, nodes, nodes_len);
		int y_index = _get_node_index(y, nodes, nodes_len);

		if (x_index < y_index) {
			nodes[x_index] = new_node;

			H_NODE* save = nodes[nodes_len - 1];
			nodes[nodes_len - 1] = y;
			nodes[y_index] = save;
		} else {
			nodes[y_index] = new_node;

			H_NODE* save = nodes[nodes_len - 1];
			nodes[nodes_len - 1] = x;
			nodes[x_index] = save;
		}
		nodes_len--;
	}

	H_NODE* head = nodes[0];
	
	free(nodes);

	return head;
}

void _get_two_least_frequent(H_NODE** nodes, int nodes_len, H_NODE** out_first, H_NODE** out_second) {
	// Returns 2 elements with least frequency and saves them to out_first and out_second

	H_NODE* elem1 = nodes[0];
	H_NODE* elem2 = NULL;

	for (int i = 1; i < nodes_len; i++) {
		if (nodes[i]->freq <= elem1->freq) {
			elem2 = elem1;
			elem1 = nodes[i];
		} else if (!elem2)
			elem2 = nodes[i];

	}

	*out_first = elem1;
	*out_second = elem2;

	return;
}

H_NODE** get_frequencies(unsigned char* input, size_t input_len, int *out_len) {
	// Builds the initial array of frequencies, returns its length via out_len

	int f_array_len = 0;
	H_NODE** f_array = (H_NODE**)calloc(0, sizeof(H_NODE*));
	
	int entry_index = -1;
	for (int i = 0; i < input_len; i++) {
		if ((entry_index = _entry_exists(input[i], f_array, f_array_len)) >= 0)
			f_array[entry_index]->freq++;
		else {
			// Create new node
			H_NODE* f_array_elem = (H_NODE*)malloc(sizeof(H_NODE));
			f_array_elem->element = input[i];
			f_array_elem->freq = 1;
			f_array_elem->left = f_array_elem->right = NULL;
			
			// Make space for new node
			f_array = (H_NODE**)realloc(f_array, ++f_array_len * sizeof(H_NODE*));

			// Insert new node
			f_array[f_array_len - 1] = f_array_elem;
		}
	}

	*out_len = f_array_len;
	return f_array;
}

void print_huffman_tree(H_NODE* head) {
	_print_huffman_tree(head, 0);

	return;
}

void free_huffman_tree(H_NODE* head) {
	// Should work, didn't test it with valgrind
	
	if (!head->left && !head->right) {
		free(head);
		return;
	}

	if (head->left) free_huffman_tree(head->left);
	if (head->right) free_huffman_tree(head->right);

	free(head);

	return;
}


// ================UTILITY DEFN================

unsigned char* _search_dict(unsigned char e, H_DICT_ELEM* dict, int dict_len) {
	for (int i = 0; i < dict_len; i++)
		if (dict[i].element == e) return dict[i].code;

	return NULL;
}

H_DICT_ELEM* _get_dict(unsigned char* input, size_t input_len, H_NODE* head, int *out_dict_len) {
	int dict_len = 0;
	H_DICT_ELEM* huffman_dict = (H_DICT_ELEM*)malloc(0);

	for (int i = 0; i < input_len; i++) {
		if (!_is_in_dict(input[i], huffman_dict, dict_len)) {
			char* code = _get_code(input[i], head);
			
			huffman_dict = (H_DICT_ELEM*)realloc(huffman_dict, ++dict_len * sizeof(H_DICT_ELEM));

			huffman_dict[dict_len - 1].element = input[i];
			huffman_dict[dict_len - 1].code = code;
		}
	}

	*out_dict_len = dict_len;

	return huffman_dict;
}

unsigned char* _get_code(unsigned char e, H_NODE* head) {
	unsigned char* output = (unsigned char*)malloc(sizeof(unsigned char));
	output[0] = '\0';

	if (!_get_code_rec(e, head, output))
		return NULL; // Not found, shouldn't happen

	return output;	
}

bool _get_code_rec(unsigned char e, H_NODE* current, unsigned char* current_code) {
	if (!current->left && !current->right) {
		if (current->element == e) {
			return true;
		} else {
			current_code[strlen(current_code) - 1] = '\0';
			return false;
		}
	}

	if (_get_code_rec(e, current->right, _str_concat(&current_code, "1")))
		return true;

	if (_get_code_rec(e, current->left, _str_concat(&current_code, "0")))
		return true;

	current_code[strlen(current_code) - 1] = '\0';

	return false;
}

void _print_huffman_tree(const H_NODE* node, int indentation) {
	if (!node) return;

	for (int i = 0; i < indentation; i++)
		printf("  ");

	if (indentation > 0)
		printf("- ");

	if (node->element == '\n')
		printf("[NL|%d]\n", node->freq);
	else
		printf("[0x%x|%d]\n", node->element, node->freq);

	_print_huffman_tree(node->left, indentation + 1);
	_print_huffman_tree(node->right, indentation + 1);

	return;
}

bool _is_in_dict(unsigned char e, H_DICT_ELEM* dict, int dict_len) {
	for (int i = 0; i < dict_len; i++)
		if (dict[i].element == e) return true;

	return false;
}

int _entry_exists(unsigned char e, H_NODE** array, int array_len) {
	// Returns index of the element if found, otherwise -1

	for (int i = 0; i < array_len; i++)
		if (array[i]->element == e) return i;

	return -1;
}

int _get_node_index(H_NODE* node, H_NODE** nodes, int nodes_len) {
	for (int i = 0; i < nodes_len; i++)
		if (nodes[i] == node) return i;

	return -1;
}

// This implementation is meant to be used only in this project
unsigned char* _str_concat(unsigned char** dest, unsigned char* src) {
	int dest_len = strlen(*dest);
	*dest = (unsigned char*)realloc(*dest, (dest_len + strlen(src) + 1) * sizeof(unsigned char));

	memmove(&(*dest)[dest_len], src, strlen(src));
	(*dest)[dest_len + strlen(src)] = '\0';

	return *dest;

}

// ============================================

