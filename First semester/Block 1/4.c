#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int a, i;
	scanf("%d", &a);
	i = 2;
re:
	if (a % i == 0 && a > 2 || a==1)
	{
		printf("NO");
		goto end;
	}
	i++;
	if (i < a) goto re;
	printf("YES");
end:
	return 0;
}