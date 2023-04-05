#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
int32_t arr[2000002];
int32_t res[2000002];
int reslen=0;
//merges sorted arrays a[0..ak-1] and b[0..bk-1] into
//one sorted array res[0..rk-1], returning rk from function
int merge(const int* a, int ak, const int* b, int bk, int* res) {
	int i=0, j=0;
	while (i<ak && j<bk) {
		if (a[i] <= b[j]) res[i + j] = a[i++];
		else res[i + j] = b[j++];
	}
	if (i == ak)
		while (j<bk) res[i + j] = b[j++];
	else while (i < ak) res[i + j] = a[i++];
	int rk = i + j;
	return (rk);
}
/*int solve(int* arr, int length) {
	if (length == 1) return (1);
	int* arrL = arr;
	int lenL = length/2;
	int lenR = length - lenL;
	int* arrR = &arr[lenL];
	int resL = solve(arrL, lenL);
	int resR = solve(arrR, lenR);
	reslen += merge(arrL, resL, arrR, resR, res);
	return (reslen);
}*/

int main() {
	FILE* fp = fopen("input.bin", "rb");
	fread(arr, 4, 2, fp);
	int N = arr[0];
	int M = arr[1];
	fread(&arr[2], 4, N, fp);
	fread(&arr[N+2], 4, M, fp);
	fclose(fp);
	//printf("%d %d", arr[0], arr[1]);
	//solve(&arr[2],N+M);
	merge(&arr[2], N, &arr[N + 2], M, res);
	fp = fopen("output.bin", "wb");
	fwrite(res, 4, N+M, fp);
	fclose(fp);
	return 0;
}