#include <stdio.h>
#include<stdlib.h>


typedef struct node { 
	int item; 
	struct node *next;
} NODE;


NODE *head = NULL;


void push(int x) {
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->item = x;
	new_node->next = NULL;

	if (head)
		new_node->next = head;

	head = new_node;

	return;
}

int pop() {
	if (!head) return -100;

	int item = head->item;
	NODE* next = head->next;

	free(head);

	head = next;

	return item;
}

int empty() {
	return !head;
}

int main(){
	int i;
	int x;
	int head1;

	for(i = 0; i < 10; i++) {
		scanf ("%d", &x);
		push(x);
	}

	printf("czy pusty=%d\n",empty());
	for(; !empty();)
		printf("+++ze stosu: %d\n", pop());
}

