#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, s, i;
	scanf("%d", &i);
	s = 0;
re:
	scanf("%d", &a);
	if (a % 2 == 0) s += a;
	i--;
	if (i > 0) goto re;
	printf("%d", s);
	return 0;
}