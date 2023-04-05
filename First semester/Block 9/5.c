#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
int32_t arr[1000001];
//partitions array a[0..n-1] into two subarrays, returning value k
// the subarray a[0..k-1] must have all elements <= pivot
// the subarray a[k..n-1] must have all elements >= pivot
void partition(int* a, int n) {
	if (n <= 2) {
		if (n == 2)
			if (a[0] > a[1]) { int temp = a[1]; a[1] = a[0]; a[0] = temp; }
		return;
	} 
	int k = ((rand() << 15) ^ rand()) % n;
	int pivot = a[k];
	int i=0, j=n;
	do {
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;

		if (i <= j) {
			 int temp = a[i]; a[i] = a[j]; a[j] = temp;
			i++; j--;
		}
	} while (i <= j);
	if (j > 0) partition(a, j);
	if (n > i) partition(a + i, n - i);
}
//no check for strange rule |u-v|<1
int main() {
	FILE* fp = fopen("input.bin", "rb");
	fread(arr, 4, 1, fp);
	int N = arr[0];
	fread(&arr[1], 4, N, fp);
	fclose(fp);
	
	partition(&arr[1], N-1);
	
	fp = fopen("output.bin", "wb");
	fwrite(&arr[1], 4, N, fp);
	fclose(fp);
	return 0;
}