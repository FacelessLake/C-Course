#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int arr[300001];
int res[300001];

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
	int i, N;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	mergeSort(arr,N);
	int counter = 0;
	res[0] = arr[0];
	for (i = 1; i < N; i++) {
		if (res[counter] != arr[i]) {
			counter++;
			res[counter] = arr[i];
		}
	}
	counter++;
	printf("%d\n", counter);
	for (i = 0; i < counter; i++) {
		printf("%d\n", res[i]);
	}
	return 0;
}