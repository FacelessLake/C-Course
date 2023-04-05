#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int a, b, max, max_c=1, min, min_c=1, i;
	scanf("%d", &a);
	scanf("%d", &max);
	min = max;
	for (i = 2; i <= a; i++) {
		scanf("%d", &b);
		if (b > max) {
			max = b;
			max_c = i;
		}
		if (b < min) {
			min = b;
			min_c = i;
		}
	}
	printf("%d ""%d ""%d ""%d ",min,min_c,max,max_c);
	return 0;
}