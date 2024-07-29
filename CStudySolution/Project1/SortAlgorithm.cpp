#include <iostream>
#include "SortAlgorithm.h"

template <typename T>
inline void SimpleSwap(T* a, T* b)
{
	T temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void SelectSort(int arr[], int length, bool MinToMax)
{
	if (arr == NULL || length <= 0)
	{
		std::cout<<"\nError : Invalid array param in function SelectSort";
		return;
	}
	if (length == 1)
	{
		std::cout<<"array length is 1, no need to sort";
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
		SimpleSwap(&arr[TargetIndex], &arr[i]);
	}
	
	return;
}

void PrintIntArray(int arr[], int length)
{
	if (arr == NULL || length <= 0)
	{
		std::cout<<"Error : Invalid array on PrintIntArray function";
		return;
	}
	std::cout<<"array value is : {";
	for (int i = 0; i < length; i++)
	{
		std::cout<<arr[i];
	}
	std::cout<<"\n";

	return;
}