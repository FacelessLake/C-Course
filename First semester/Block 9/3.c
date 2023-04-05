#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
	int arr[300001];
	
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
		int N;
		long long answ = 0;
		scanf("%d",&N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}
		if (N == 1) { printf("%d", arr[0]); return 0; }
		mergeSort(&arr, N);
		for (int i = 0; i < N-1; i++) {//simple combinatorics
			int iter = N - 1 -i;
			answ += ((long long)arr[i] * iter);
		}
		printf("%lld",answ);
		return 0;
	}