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

int factorial(int n)
{
	if (n<0)//check n is negative
	{
		std::cout<<"Error_factorial : input nagative number"<<std::endl;
		return -1;
	}
	if (n == 0)
	{
		return 1;
	}
	return n*(n+1)/2;
}

int power(int Basement, int exponential)
{
	if (exponential==0)
	{
		return 1;
	}

	int ReturnValue = 1;
    
	if (exponential<0) //negative exponential
	{
		//I do not have logic to process negative exponential calc
	}
	else //positive exponential
	{
		while(exponential != 0) 
		{
			if (exponential % 2 == 1) //Odd exponential?
			{
				exponential--;
				ReturnValue *= Basement;
			}
			else //if exponential is positive, make exponential half over and over again until it reaches at 1
			{
				exponential = exponential/2;
				Basement = Basement*Basement; //To make exponential number become half, we need to square basement number    
			}
		}
		return ReturnValue;
	}
}

int FibWithRecursion(int n)
{
	if (n==0) return 0;
	if (n==1) return 1;

	return FibWithRecursion(n-1)+FibWithRecursion(n-2);
}
int FibWithLoop(int n)
{
	if (n<0)
	{
		std::cout<<"Nagative Input in FibWithLoop function"<<std::endl;
		return -1;
	}
	if (n==0) return 0;
	if (n<=2) return 1;

	int n_0 = 2; //n
	int n_1 = 1; //n-1
	int n_2 = 1; //n-2

	for (int i = 3; i<n; i++) //calc n-1, n-2 to get n
	{
		n_2 = n_1;
		n_1 = n_0;
		n_0 = n_2 + n_1;
	}

	return n_0;
}

void Hanoi(int DiskNum, int Pillar_From, int Pillar_Target, int Pillar_Auxilary)
{
	if (DiskNum <= 0) return;
	if (DiskNum == 1)
	{
		std::cout<<"("<<Pillar_From<<", "<<Pillar_Target<<")"<<std::endl;
		return;
	}

	Hanoi(DiskNum-1, Pillar_From, Pillar_Auxilary, Pillar_Target);
	std::cout<<"("<<Pillar_From<<", "<<Pillar_Target<<")"<<std::endl;
	Hanoi(DiskNum-1, Pillar_Auxilary, Pillar_Target, Pillar_From);
}