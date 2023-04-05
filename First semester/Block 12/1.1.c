#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void ExtractMax(int* arr, int n, int i) {
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[max])
		max = left;

	if (right < n && arr[right] > arr[max])
		max = right;

	if (max != i) {
		swap(&arr[i], &arr[max]);
		ExtractMax(arr, n, max);
	}
}

void heapSort(int* arr, int n) {

	for (int i = n - 1; i >= 0; i--) {
		swap(&arr[0], &arr[i]);
		ExtractMax(arr, i, 0);
	}
}

void Add(int* arry, int index) {
	int temp;
	while (arry[index] > arry[(index - 1) / 2] && index > 0) {
		temp = arry[(index - 1) / 2];
		arry[(index - 1) / 2] = arry[index];
		arry[index] = temp;
		index = (index - 1) / 2;
	}
	return;
}

int main() {
	int* arr = (int*)calloc(500001, sizeof(int));
	int N, i;
	FILE* fp = fopen("input1.txt", "r");
	int szElem = sizeof(int);

	fscanf(fp, "%d", N);
	
	for (i = 0; i < N; i++) {
		fread(&arr[i], szElem, 1, fp);
		if (i > 0) Add(arr, i);
	}
	fclose(fp);
	int iter = N;
	heapSort(arr, iter);

	fp = fopen("output1.txt", "w");
	fwrite(arr, szElem, N, fp);
	fclose(fp);
	free(arr);
	return 0;
}