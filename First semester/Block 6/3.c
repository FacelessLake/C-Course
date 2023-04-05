#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define large 100010

typedef struct list {
	char* string;
}list;
list arr[large];

int main() {
	int i, n, t, count, iter = 0, k;
	char value;
	scanf("%d", &n);
	while (n>0) {
		n--;
		scanf("%d", &t);
		scanf("%d", &k);
		if (t == 0) {
			arr[iter].string = malloc(k + 1);
			scanf("%s", arr[iter].string);
			iter++;
		}
		if (t == 1){
			free(arr[k].string);
			arr[k].string = NULL;
		}
		if (t == 2) {
			printf("%s\n", arr[k].string);
		}
		if (t == 3) {
			scanf(" %c", &value);
			count = 0;
			for (i = 0; i < strlen(arr[k].string); i++) {
				if (arr[k].string[i] == value) count++;
			}
			printf("%d\n", count);
		}
	}
	for (i = 0; i < large; i++) {
		free(arr[i].string);
	}
	return 0;
}