#include <stdio.h>
#include "SortAlgorithm.h"

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
		printf("\nError : Invalid array param in function SelectSort");
		return;
	}
	if (length == 1)
	{
		printf("array length is 1, no need to sort");
	}

	int i,j;
	int TargetIndex = 0;

	
	for (i = 0; i < length - 1; i++)
	{
		TargetIndex = i;
		for (j = i+1; j < length; j++)
		{
			if (MinToMax == true)
			{
				if (arr[TargetIndex] > arr[j])
				{
					TargetIndex = j; //Store Minimum value's Index
				}
			}
			else
			{
				if (arr[TargetIndex] < arr[j])
				{
					TargetIndex = j; //Store Maximum value's Index
				}
			}
		}
		SimpleIntSwap(&arr[TargetIndex], &arr[i]);
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