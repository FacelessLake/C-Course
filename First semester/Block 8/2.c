#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
uint32_t arr[100000];

uint32_t changeEnd(int val) {
	return (((val & 0xFF) << 24) | ((val & 0xFF00) << 8) | ((val >> 8) & 0xFF00) | ((val >> 24) & 0xFF));
}

int main() {
	unsigned short i, BigMode = 0;
	uint32_t N;
	FILE* fp = fopen("input.bin", "rb");
	int szElem = sizeof(arr[0]);
	fread(&N, sizeof(N), 1, fp);
	if (N > 10000) {
		N = changeEnd(N);
		BigMode = 1;
	}
	fread(arr, szElem, N, fp);
	fclose(fp);

	int counter = 0;
	fp = fopen("output.bin", "wb");
	if (BigMode == 1)
		for (i = 0; i < N; i++) {
			counter += changeEnd(arr[i]);
		}
	else
		for (i = 0; i < N; i++) {
			counter += arr[i];
		}

	if (BigMode == 1) counter = changeEnd(counter);
	fwrite(&counter, szElem, 1, fp);
	fclose(fp);

	return 0;
}