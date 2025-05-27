#include <stdio.h>
#define N 100


int stack[N];
int head=0;


void push(int x) {
	if (head >= N) return;

	stack[head++] = x;
	
	return;
}

int pop() {
	return (head == 0) ? -100 : stack[--head];
}

int size () {
	return head;
}

int full() {
	return !head;
}


int main() {
	int i, x, head1;
	for(i = 0; i < 10; i++) {
		scanf ("%d", &x);
		push(x);
	}

	for (i = 0; i < head; i++)
		printf("-- %d\n",stack[i]);

	printf ("---head=%d\n", head);
	printf("rozmiar stosu=%d\n",size());
	printf("czy pelny=%d\n",full());

	head1=head;

	for(i = 0; i < head1; i++)
		printf("+++ze stosu: %d\n", pop());

	printf ("head=%d\n", head);
}

