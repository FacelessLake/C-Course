#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int h, m, s, h1, m1, s1,a;
	scanf("%d" "%d" "%d" "%d", &h, &m, &s, &a);
	s += a;
	s1 = s % 60;
	m += s / 60;
	m1 = m % 60;
	h += m / 60;
	h1 = h % 24;
	printf("%d %d %d ", h1, m1, s1);
	return 0;
}