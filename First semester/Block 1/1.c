#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main1() {
	int a, b;
	b = 0;
	scanf("%d", &a);
re: b += a;
	a--;
	if (a == 0) goto go;
	goto re;
go:
	printf("%d", b);
	return 0;
}