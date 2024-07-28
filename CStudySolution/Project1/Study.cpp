#include <stdio.h>
#include "SortAlgorithm.h"

int main()
{
	int IntArray[] = {2,6,3,7,5,4,7,7,4};
	
	SelectSort(IntArray, 9, true);
	PrintIntArray(IntArray, 9);

	return 0;
}