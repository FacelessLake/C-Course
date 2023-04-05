#pragma once

#ifdef _WIN32 //for .dll
	#ifdef DLLIBRARY_EXPORTS //dllibrary.dll
		#define DLLIBRARY_API __declspec(dllexport)

	#else
		#define DLLIBRARY_API __declspec(dllimport)
	#endif

#else
	#define DLLIBRARY_API __attribute__((visibility("default"))) //for .so
#endif

typedef struct IntegerSet {
	int *arr;
	int n;
}IntegerSet;

DLLIBRARY_API IntegerSet* CreateSet(int* N, int n);
DLLIBRARY_API int IsInSet(IntegerSet* N, int n);