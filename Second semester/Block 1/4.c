#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// расчет факториала n
int factmod(int n, int p) {
	int res = 1;
	while (n > 1) {
		res = (res * ((n / p) % 2 ? p - 1 : 1)) % p;
		for (int i = 2; i <= n % p; ++i)
			res = (res * i) % p;
		n /= p;
	}
	return res % p;
}

// расчет C(n,k)
int binomialCoeff(int n, int k, int abs)
{
	return factmod(n, abs) / (factmod(k, abs) * factmod((n - k), abs));
}


int main(/*int argc, char** argv*/) {

	FILE* fp = fopen("input.txt", "r");
	FILE* f = fopen("output.txt", "w");
	int sz = sizeof(int);

	int* arr = calloc(1000010, sz);
	int qty, i, n, k, abs;
	
	fscanf(fp, "%d %d", &abs, &qty);//read quantity and absolute

	for (i = 0; i < qty; i++) {
		fscanf(fp, "%d %d", &n, &k);
		if (n < 0 || k < 0 || n < k) arr[i] = 0;
		else arr[i] = binomialCoeff(n, k, abs);
		fprintf(f, "%d\n", arr[i]);
	}

	fclose(fp);
	fclose(f);
	free(arr);
	return 0;
}