#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tree {
	int value;
	struct tree* left;
	struct tree* right;
} TREE;
//Fisher–Yates shuffle
void shuffle(int* arry, int N)
{
	srand(time(NULL));

	for (int i = N - 1; i >= 1; i--)
	{
		int j = rand() % (i + 1);

		int tmp = arry[j];
		arry[j] = arry[i];
		arry[i] = tmp;
	}
}

TREE* Add(TREE* root, int key) {
	if (root == NULL) {
		TREE* tree = malloc(sizeof(TREE));
		tree->left = tree->right = NULL;
		tree->value = key;
		return tree;
	}
	if (key < root->value || (key == root->value && (rand() % 2) == 0)) {
		root->left = Add(root->left, key);
	}
	else {
		root->right = Add(root->right, key);
	}
	return root;
}

void Answ(TREE* root, int* arry)
{
	static newelem = 0;//count new elements
	if (root == NULL) return;
	Answ(root->left, arry); 
	arry[newelem] = root->value; //count new elements
	newelem++;
	Answ(root->right, arry); 
	free(root);
}

void TreeSort(int* arry, int elem_total)
{
	TREE* root;
	root = NULL;
	for (int i = 0; i < elem_total; i++)
		root = Add(root, arry[i]);
	Answ(root, arry);
}

int arr[500001];
int main() {
	//int* arr = calloc(500001, sizeof(int));
	int N, i;
	FILE* fp = fopen("input.bin", "rb");
	int szElem = sizeof(int);

	fread(&N, szElem, 1, fp);
	fread(arr, szElem, N, fp);
	fclose(fp);
	int iter = N;
	shuffle(arr, iter);
	TreeSort(arr, iter);

	fp = fopen("output.bin", "wb");
	fwrite(arr, szElem, N, fp);
	fclose(fp);
	//free(arr);
	return 0;
}