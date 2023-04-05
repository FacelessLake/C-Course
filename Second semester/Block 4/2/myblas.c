#include "cblas.h"
void cblas_dgemm(
	const int order,
	const int transa,
	const int transb,
	const int m,
	const int n,
	const int k,
	const double alpha,
	const double* A,
	const int lda,
	const double* B,
	const int ldb,
	const double beta,
	double* C,
	const int ldc) {
		
	double answ = 0;

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