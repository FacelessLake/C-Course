#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000100

typedef struct list {
	int value;
	int next;
	int preveous;
}list;

list arr[SIZE];

int main() {
	int i, T, N, F, L, Q, t, n, k;
	scanf("%d", &T);
	while(T > 0) {
		T--;
		scanf("%d %d %d %d", &N, &F, &L, &Q);
		arr[0].next = ++F;
		arr[0].preveous = ++L;
		for (i = 1; i <= N; i++) {
			scanf("%d %d %d", &arr[i].value, &arr[i].next, &arr[i].preveous);
			arr[i].next++;
			arr[i].preveous++;
		}
		for (i = 0; i < Q; i++) {
			scanf("%d %d", &t, &n);
			n++;
			if (t == 1) {
				k = ++N;
				arr[k].value = malloc(sizeof(list));
				scanf("%d", &arr[k].value);
				if (n != -1) {
					arr[k].preveous = n;
					arr[k].next = arr[n].next;
					arr[arr[n].next].preveous = k;
					arr[n].next = k;
				}
				else arr[k].next = 0;
				printf("%d\n", --k);
			}
			else if (t == -1) {
				k = ++N;
				arr[k].value = malloc(sizeof(list));
				scanf("%d", &arr[k].value);
				if (n != -1) {
					arr[k].next = n;
					arr[k].preveous = arr[n].preveous;
					arr[arr[n].preveous].next = k;
					arr[n].preveous = k;
				}
				else arr[k].preveous = 0;
				printf("%d\n", --k);
			}
			else if (t == 0) {
				arr[arr[n].preveous].next = arr[n].next;
				arr[arr[n].next].preveous = arr[n].preveous;
				printf("%d\n", arr[n].value);
			}
		}
		printf("===\n");

		i = arr[0].next;
		while (i != 0) {
			printf("%d\n", arr[i].value);
			i = arr[i].next;
		}
		printf("===\n");
	}
	return 0;
}