#include <stdio.h>

#ifndef SORT_ALGORITHM_H
#define SORT_ALGORITHM_H

void SimpleIntSwap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void SelectSort(int arr[], int length, bool MinToMax)
{
	if (arr == NULL || length <= 0)
	{
		printf("\nError : Invalied array param in function SelectSort");
		return;
	}
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = i; j < length; j++)
		{
			if (MinToMax == false)
			{
				if (arr[i] < arr[j])
				{
					SimpleIntSwap(&i,&j);
				}
			}
			else
			{
				SimpleIntSwap(&i,&j);
			}
		}
	}

	return;
}

void PrintIntArray(int arr[], int length)
{
	if (arr == NULL || length <= 0)
	{
		printf("Error : Invalid array on PrintIntArray function");
		return;
	}
	printf("array value is : {");
	for (int i = 0; i < length; i++)
	{
		printf(" %d", arr[i]);
	}
	printf("}\n");

	return;
}

#endif // !SORT_ALGORITHM_H
