#include <stdio.h>

#define N 100


int fifo[N];
int head=0;
int tail=0;
int l=0;


/* 6 2 3 4 5 | 6 2 3 4
 * T   H     |   T
 *
 * 1. put(1) -> l != 5 -> fifo[0] = 1 -> tail++ (tail = 1 | head = 0 | l = 1)
 * 2. put(2) -> l != 5 -> fifo[1] = 2 -> tail++ (tail = 2 | head = 0 | l = 2)
 * 3. put(3) -> l != 5 -> fifo[2] = 3 -> tail++ (tail = 3 | head = 0 | l = 3)
 * 4. put(4) -> l != 5 -> fifo[3] = 4 -> tail++ (tail = 4 | head = 0 | l = 4)
 * 5. put(5) -> l != 5 -> fifo[4] = 5 -> tail++ (tail = 5 | head = 0 | l = 5)
 * 6. get()  -> v = 1  -> l-- = 4 -> (tail = 5 | head = 1 | l = 4)
 * 7. get()  -> v = 2  -> l-- = 3 -> (tail = 5 | head = 2 | l = 3)
 * 8. get(6) -> l != N -> fifo[T % N = 0] = 6 -> tail++ (tail = 6 | head = 0 | l = 4)
 *
 */

void put(int x) {
	if (l == N) return;

	fifo[tail % N] = x;

	if (l != N) tail++;

	l++;

	return;
}

int get() {
	int value = fifo[head++];
	l--;

	return value;
}

int full() {
	return l == N;
}

int empty() {
	return !l;
}

int main() {
	int i;
	int x;

	for(i = 0; i < 10; i++)
	{
		scanf("%d", &x);
		put(x);
	}

	for ( i = head; i < head + l; i++)
		printf("-- %d\n",fifo[i]);

	printf("dlugosc kolejki=%d\n", l);
	printf("--- head=%d\n--- tail=%d\n", head, tail);
	printf("czy pelny=%d\n", full());
	printf("czy pusty=%d\n", empty());

	for(i = 0; i < 10; i++) {
		printf("+++z fifo: %d\n", get());

		printf("dlugosc kolejki=%d\n", l);
		printf ("--- head=%d\n--- tail=%d\n", head, tail);
	}
}

