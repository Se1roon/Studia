#include <stdio.h>
#include<stdlib.h>

typedef struct node { 
	int item; 
	struct node *next;
} NODE;


NODE *head=NULL;
NODE *tail=NULL;


void put(int x) {
	NODE* new_node = (NODE *)malloc(sizeof(NODE));
	new_node->item = x;
	new_node->next = NULL;

	if (!head)
		head = new_node;
	else 
		tail->next = new_node;

	tail = new_node;

	return;
}

int get() {
	int value = head->item;
	NODE* next = head->next;

	free(head);
	head = next;

	return value;
}

int empty() {
	return !head;
}

int main() {
	int i;
	int x;

	for(i = 0; i < 10; i++) {
		scanf ("%d", &x);
		put(x);
	}

	printf("czy pusty=%d\n",empty());
	for(; !empty();) {
		printf("+++z FIFO: %d\n", get());
	}
}

