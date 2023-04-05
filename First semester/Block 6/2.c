#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#define large 1000010

typedef struct list{
	int next;
	char data[8];
}list;

list arr[large];
int main() {
	int T,i; //
	int oper; //
	int N,F,Q;
	int k;
	char str[8];
	int n; //
	scanf("%d", &T);
	while (T > 0) {
		T--;
		scanf("%d %d %d", &N, &F, &Q);
		for (int j = 0; j < N; j++) {
			scanf("%s", &arr[j].data);
			scanf("%d", &arr[j].next);
		}
		for (i = 0; i < Q; i++) {
			scanf("%d", &oper);
			scanf("%d", &n);
			if (oper == 0) {
				scanf("%s", str);
				k = N++;
				printf("%d\n", k);
				strcpy(arr[k].data, str);

				if (n == -1) {
					arr[k].next = F;
					F = k;
				}
				else if (n != -1) {
					arr[k].next = arr[n].next;
					arr[n].next = k;
				}
			}
			
			else if (oper == 1) {
				if (n == -1) {
					printf("%s\n", arr[F].data);
					F = (arr[F].next);
				}
				else if (n != -1) {
					printf("%s\n", arr[arr[n].next].data);
					arr[n].next = arr[arr[n].next].next;
				}
			}
		}
		printf("===\n");
		for (int y = F; y != -1; y = arr[y].next) {
			printf("%s\n", arr[y].data);
		}
		printf("===\n");
	}
	return 0;
}