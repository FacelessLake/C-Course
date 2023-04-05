#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int a, b, c, d, e, f;
	scanf("%d" "%d", &a, &b);
	if (a >=0) {
		f = a % b;
		c = a / b;
		if (f == 0) d = c;
		else d = c + 1;
		e = c;
	}
	else {
		f = a % b;
		d = a / b;
		if (f == 0) c = d;
		else c = d - 1;
		e = d;
		if (f != 0) f += b;
	}
	printf("%d " "%d " "%d " "%d ", c, d, e, f);
	return 0;
}