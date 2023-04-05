#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int32_t arr[500001];
int32_t res[500001];
//int reslen = 0;

void merge(int left[], int n, int right[], int m, int res[]) {
	int leftid = 0, rightid = 0;
	while (leftid != n && rightid != m) {
		if (left[leftid] <= right[rightid]) {
			res[leftid + rightid] = left[leftid];
			leftid++;
		}
		else {
			res[leftid + rightid] = right[rightid];
			rightid++;
		}
	}
	while (leftid != n) res[leftid + rightid] = left[leftid++];
	while (rightid != m) res[leftid + rightid] = right[rightid++];
}

void mergeSort(int ary[], int len) {
	if (len <= 1) return;

	int mid = len / 2;

	mergeSort(ary, mid);
	mergeSort(ary + mid, len - mid);

	int tsize = sizeof(int) * len;
	int* tmp = malloc(tsize);
	merge(ary, mid, ary + mid, len - mid, tmp);
	memcpy(ary, tmp, tsize);
	free(tmp);
}

int main() {
	FILE* fp = fopen("input.bin", "rb");
	fread(arr, 4, 1, fp);
	int N = arr[0];
	fread(&arr[1], 4, N, fp);
	fclose(fp);

	mergeSort(&arr[1],N);

	fp = fopen("output.bin", "wb");
	fwrite(&arr[1], 4, N, fp);
	fclose(fp);
	return 0;
}