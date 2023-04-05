#define _CRT_SECURE_NO_WARNINGS
#include "myblas.h"

void dgemv(
	int m, int n,
	double alpha, const double* A, const double* X,
	double beta, double* Y
) {
	double answ=0;
	for (int i = 0; i < m; i++) {
		answ = 0;
		for (int j = 0; j < n; j++) {
			answ += A[n * i + j] * X[j];
		}
		Y[i] = answ * alpha + Y[i] * beta;
	}
}


void dger(
	int m, int n,
	double alpha, const double* X, const double* Y,
	double* A
) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			A[i * n + j] += alpha * X[i] * Y[j];
		}
	}
}