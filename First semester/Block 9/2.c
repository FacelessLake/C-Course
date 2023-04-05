#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
int32_t arr[1000100];
int32_t l[1000002];
int32_t r[1000002];
//partitions array a[0..n-1] into two subarrays, returning value k
// the subarray a[0..k-1] must have all elements <= pivot
// the subarray a[k..n-1] must have all elements >= pivot
int partition(int* a, int n, int pivot) {
	int i, left=0, right = 0, sw=0;
	for (i = 0; i < n; i++) {
		if (a[i] < pivot) {
			l[left] = a[i];
			left++;
		}
		if (a[i] == pivot) {
			if (sw == 0) {
				l[left] = a[i];
				sw = 1;
				left++;
			}
			else{
				r[right] = a[i];
				sw = 0;
				right++;
			}
		}
		if (a[i] > pivot) {
			r[right] = a[i];
			right++;
		}
	}
	
	for (i = 0; i < left; i++) {
		a[i] = l[i];
	}
	for (i = left; i < n; i++) {
		a[i] = r[i-left];
	}
	return (left);
}


int main() {
	FILE* fp = fopen("input.bin", "rb");
	fread(arr, 4, 2, fp);
	int N = arr[0];
	int p = arr[1];
	fread(&arr[2], 4, N, fp);
	fclose(fp);
	int k = partition(&arr[2], N, p);
	fp = fopen("output.bin", "wb");
	fwrite(&k, 4, 1, fp);
	fwrite(&arr[2], 4, N, fp);
	fclose(fp);
	return 0;
}