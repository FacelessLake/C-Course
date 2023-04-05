#define _CRT_SECURE_NO_WARNINGS
#include "integerset.h"
#include <stdlib.h>

void quickSort(int* numbers, int left, int right)
{
    int pivot;
    int l_hold = left;
    int r_hold = right;
    pivot = numbers[left];
    while (left < right)
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            numbers[left] = numbers[right];
            left++;
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++;
        if (left != right)
        {
            numbers[right] = numbers[left];
            right--;
        }
    }
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        quickSort(numbers, left, pivot - 1);
    if (right > pivot)
        quickSort(numbers, pivot + 1, right);
}

int binary(int num, int *arr, int n){

    int left, right, middle, tmp;

    left = 0;
    right = n - 1;
    
    while (left <= right){
        tmp = left + right;
        middle = (tmp) / 2;
        
        if (num < arr[middle])
            right = middle - 1;
        else if (num > arr[middle])
            left = middle + 1;
             else
                 return 1;
    }
    return 0;
}

int IsInSet(IntegerSet* N, int num) {
    int m;
	if (N == 0)
		return 0;
    m = binary(num, N->arr, N->n);
    if (m == 0)
        return 0;
    return 1;
}

IntegerSet* CreateSet(int* arr, int sz) {
    IntegerSet* tmp;
    int i;
    tmp = malloc(sizeof(IntegerSet));
    tmp->n = sz;
    
    tmp->arr = calloc(tmp->n, sizeof(int));
    
    for (i = 0; i < tmp->n; i++) {
        tmp->arr[i] = arr[i];
    }

    quickSort(tmp->arr, 0, (tmp->n)-1 );
    
    for (i = 1; i < sz; i++) {
        if (tmp->arr[i] == tmp->arr[i - 1]) {
            return 0;
        }
    }
    return tmp;
}
