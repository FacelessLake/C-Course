#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int Nod(int a, int b)
{
	while (a > 0 && b > 0)
		if (a > b)
			a %= b;
		else
			b %= a;
	return a + b;
}

int main() {
	int i, answ, N;
	scanf("%d", &N);
	int* a = calloc(N, sizeof(int));
	int* b = calloc(N, sizeof(int));
	for (i = 0; i < N; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	for (i = 0; i < N; i++) {
		answ = Nod(a[i], b[i]);
		printf("%d\n", answ);
	}
	free(a);
	free(b);
	return 0;
}