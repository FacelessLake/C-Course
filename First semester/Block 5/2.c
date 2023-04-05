#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
double arr[10001];
double binomialCoeff(double n, double k)
{
	double res = 1;
	if (k > n - k)
		k = n - k;

	for (double i = 0; i < k; ++i) {
		res *= (n - i);
		res /= (i + 1);
	}

	return res;
}

int main()
{
	int q,i;
	double n, k;
	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		scanf("%lf %lf", &n, &k);
		arr[i] = binomialCoeff(n, k);
	}
	for (i = 0; i < q; i++) {
		printf("%0.10g\n", arr[i]);
	}
	return 0;
}