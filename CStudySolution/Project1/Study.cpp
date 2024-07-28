#include <stdio.h>
#include "SortAlgorithm.h"

#define ARRAY_LENGTH(x) {sizeof(x)/sizeof(int)}

int main()
{
	int IntArray[] = {2,6,3,7,5,4,7,7,4,9};
	
	SelectSort(IntArray, ARRAY_LENGTH(IntArray), false);
	PrintIntArray(IntArray, ARRAY_LENGTH(IntArray));

	return 0;
}