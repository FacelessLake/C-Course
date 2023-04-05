#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b, c, S;
	b = 0;
	scanf("%d %d %d", &a, &b, &c);
	if (a <= 0) printf("%d", -1);
	else if (b <= 0) printf("%d", -2);
	else if (c <= 0) printf("%d", -3);
	else {
		S = 2 * (a * b + a * c + b * c);
		printf("%d", S);
	}
	return 0;
}