#define _CRT_SECURE_NO_WARNINGS
#include "myblas.h"

void dgemm(
	int m, int n, int k,
	double alpha, const double* A, const double* B,
	double beta, double* C
) {
	double answ=0;
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			answ = 0;
			for (int t = 0; t < k; t++) {
				answ += A[i * k + t] * alpha * B[t * n + j];
			}
			C[i * n + j] = answ + C[i * n + j] * beta;
		}
	}
}