#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
int32_t arr[3];

int main() {

	FILE* fp = fopen("input.bin", "rb");
	int szElem = sizeof(arr[0]);
	int res = fread(arr, szElem, 2, fp);
	fclose(fp);

	int64_t counter;
	fp = fopen("output.bin", "wb");
	counter = arr[0];
	counter += arr[1];
	if (counter < 0 && counter % 2 != 0) arr[2]--;
	counter /= 2;
	arr[2] += counter;
	res = fwrite(&arr[2], szElem, 1, fp);
	fclose(fp);

	return 0;
}