#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int value;
	int next;
	int previous;
}list;

list arr[5010];
list victim;

int main() {
	int i, N, K, remain, counter;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) {
		arr[i].value = i;
		if (i == N) arr[i].next = 1;
		else arr[i].next =i+1;
		if (i == 1) arr[i].previous = N;
		else arr[i].previous = i - 1;
	}
	remain = N;
	counter = 1;
	victim = arr[N];
	while (remain !=0) {
		for (i = counter; i < counter+K; i++) {
			victim = arr[victim.next];
		}
		arr[victim.previous].next = victim.next;
		arr[victim.next].previous = victim.previous;
		printf("%d\n", victim.value);
		counter = i % N;
		remain--;
	}
	return 0;
}