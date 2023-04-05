#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct L {
	int value;
	int key;
	int next;
}List;


void eventest(void* ctx, int* value) {
	int* ictx = (int*)ctx;
	if (*value % 2 == 0) *ictx += *value;
}

typedef void (*callback)(void* ctx, int* value);

void arrayForeach(void* ctx, callback func, int* arr, int n) {
	int i;
	int* ictx = (int*)ctx;
	for (i = 1; i <= n; i++) {
		func(ictx, &arr[i]);
	}
}
void listForeach(void* ctx, callback func, int* sum, int n) {
	int i,next;
	List* list = (List*)ctx;
	func(sum, &list[1].value);
	next = list[1].next;
	for (i = 2; i <= n; i++) {
		func(sum, &list[next].value);
		next = list[next].next;
	}
}


int main() {
	int arr[101];
	List list[101];
	int i,N,elem;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &elem);
		arr[i] = elem;
		list[i].value = elem;
		list[i].key = i;
		if (i != N) list[i].next = i + 1;
		else list[i].next = 1;
	}
	callback t;
	t = eventest;
	int answarr=0, answlist = 0;
	arrayForeach(&answarr, t, arr, N);
	listForeach(list, t, &answlist, N);
	printf("%d %d",answarr, answlist);
	return 0;
}