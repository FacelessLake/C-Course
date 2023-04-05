#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vector {
	int key;
	int cnt;
	int cap;
	char** string;
}Vector;
Vector arr[1000001];

void push(Vector* v, char* x) {
	int size = strlen(x)+1;
	if (v->cnt == v->cap) {
		if (v->cap == 0) {
			v->cap++;
			v->string = malloc(sizeof(x));
		}
		else {
			v->cap = v->cap * 2;
			v->string = realloc(v->string, v->cap * sizeof(x));
		}
	}
	v->string[v->cnt] = malloc(size);
	strcpy(v->string[v->cnt++], x);
	return;
}

int main() {
	int N, i;
	char string[7];
	int key;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %s", &key, &string);
		push(&arr[key], string);
	}

	int j, counter = 0;
	for (i = 0; i < 1000001; i++) {
		if (counter == N) break;
		if (arr[i].cnt != 0)
			for (j = 0; j < arr[i].cnt; j++) {
				printf("%d %s\n", i, arr[i].string[j]);
				counter++;
			}
	}
	free(arr->string);
	return 0;
}