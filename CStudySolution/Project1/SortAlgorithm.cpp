#include <iostream>
#include "SortAlgorithm.h"

template <typename T>
inline void SimpleSwap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

void BubbleSort(int arr[], int length, bool MinToMax)
{
	for (int i = 0; i < length - 1; i++)
	{
		bool swap_done = false;
		for (int j = i; j < length - 1; j++)
		{
			if (MinToMax ? arr[j] > arr[j+1] : arr[j] < arr[j+1])
			{
				SimpleSwap<int>(arr[j], arr[j+1]);
				swap_done = true;
			}
		}
		if (!swap_done)
		{
			break;
		}
	}
}

void InsertSort(int arr[], int length, bool MinToMax)
{
	int i,j,k;
	int temp;

	for (i = 1; i < length; i++)
	{
		std::cout<<"Current i "<<i<<std::endl;
		if (i == 3)
		{
			std::cout<<"Debug Start"<<std::endl;
		}
		temp = arr[i];
		for (j = 0; j < i; j++) //find insertion point
		{
			if (MinToMax ? arr[i] < arr[j] : arr[i] > arr[j])
			{
				break;
			}
		}

		for (k = i; k >= j + 1; k--) //shift right
		{
			arr[k] = arr[k-1];
		}
		arr[j] = temp; //deal with insertion point

	}
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
		//std::cout<<"array length is 1, no need to sort";
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
		SimpleSwap(arr[TargetIndex], arr[i]);
	}
	
	return;
}

void SelectSortVector(std::vector<int>& arr, bool MinToMax)
{
	int i,j,k;

	for (i = 0; i < arr.size(); i++)
	{
		k = i;
		for (j = i+1; j<arr.size(); j++)
		{
			if (MinToMax ? arr[j] < arr[k] : arr[j] > arr[k])
			{
				k = j;
			}
		}
		std::swap(arr[i], arr[k]);
	}
}

void QuickSortVector(std::vector<int>& arr, int Range_L, int Range_R)
{   
	if (Range_R == INT_MAX) Range_R = arr.size()-1; //if default value, auto update
	int SortTarget = Range_L;  // This should be the pivot position
    int LeftTarget = Range_L + 1;
    int RightTarget = Range_R;

	if (LeftTarget > arr.size()-1) return; //left target is in boundary?
	if (Range_L == Range_R) return;
	if (LeftTarget > RightTarget)
	{
		return;
	}

	while(LeftTarget <= RightTarget)
	{
		while (LeftTarget < Range_R && arr[LeftTarget] < arr[SortTarget]) //find LeftTarget
		{
			LeftTarget++;
		}
		while (RightTarget >= Range_L && arr[RightTarget] > arr[SortTarget]) //find RightTarget
		{
			RightTarget--;
		}
		
		if (LeftTarget >= RightTarget) //i need to finish compare process?
		{
			break;
		}
		else
		{
			std::swap(arr[LeftTarget], arr[RightTarget]);
			LeftTarget++;
			RightTarget--;
		}
	}
	
	std::swap(arr[RightTarget], arr[SortTarget]);

	if (RightTarget > 0) //RightTarget = Pivot
	{
		QuickSortVector(arr, Range_L, RightTarget-1); //left partition
	}
	if (RightTarget < arr.size()-1)
	{
		QuickSortVector(arr, SortTarget+1, Range_R); //right partition
	}
}

std::vector<int> Merge2SortedVector(std::vector<int>& arr1, std::vector<int>& arr2)
{
	if (arr1.size() == 0 || arr2.size() == 0)
	{
		std::cout<<"Merge2SortedVector : empty vector inputed"<<std::endl;
	}

	//assume 2 arrays are sorted
	int i = 0;
	int j = 0;
	std::vector<int> arr_return;

	while(i < arr1.size() || j < arr2.size())
	{
		if(arr1[i] < arr2[j])
		{
			arr_return.push_back(arr1[i]);
			i++;
		}
		else
		{
			arr_return.push_back(arr2[j]);
			j++;
		}
	}

	for(; j<arr2.size(); j++)
	{
		arr_return.push_back(arr2[j]);
	}

	for(; i<arr1.size(); i++)
	{
		arr_return.push_back(arr1[i]);
	}
	return arr_return;
}
void MergeSortVector_Iterate(std::vector<int>&arr)
{
	if (arr.size() == 0) //array is empty?
	{
		return;
	}
	bool odd = arr.size() % 2 ? true:false;

	int i,j,SortedChunkEndIndex;
	int RemainElementSize;
	int Sort_interval;
	int Chunk_1_StartIndex, Chunk_1_EndIndex, Chunk_2_EndIndex;
	for(i = 2; i < arr.size(); i *= 2)
	{
		for(j = 0; j <= arr.size(); j += i)
		{
			SingleMergeSortVector(arr, j, ((2*j)+i-1)/2, j + i - 1); // mid = (low + high) / 2
		}
		RemainElementSize = arr.size() % i;
		if(RemainElementSize > 0) //is there any remain element that not merged?
		{
			SortedChunkEndIndex = arr.size() - RemainElementSize; //end index of currently sorted range
			Sort_interval = i;
			Chunk_1_StartIndex = SortedChunkEndIndex + 1;

			while(Sort_interval >= 1)
			{
				Sort_interval = Sort_interval/2;
				if(SortedChunkEndIndex + Sort_interval <= arr.size()-1) //is chunk1EndIndex in boundary?
				{
					Chunk_1_EndIndex = SortedChunkEndIndex + Sort_interval;
					if(Chunk_1_EndIndex + Sort_interval/2 <= arr.size()-1) //is NextChunk in boundary?
					{
						Chunk_2_EndIndex = Chunk_1_EndIndex + Sort_interval/2;
						SingleMergeSortVector(arr, Chunk_1_StartIndex, Chunk_1_EndIndex, Chunk_2_EndIndex);
						Chunk_1_EndIndex = Chunk_2_EndIndex; //shift chunk1 end index to right
					}

				}
			}

			for(int k = Chunk_1_EndIndex + 1; k <= arr.size()-1; k++) //if interval is lower then 1, merge rest partition one by one
			{
				SingleMergeSortVector(arr, Chunk_1_StartIndex, k-1, k);
			}
		}
	}
}

void SingleMergeSortVector(std::vector<int>&arr, int l, int mid, int h)
{
    // Init
    if (l == -1) l = 0;
    if (h == -1) h = arr.size() - 1;
	if (mid == -1) mid = (l + h) / 2;

    if (l >= h) return;
    

    int i = l;
    int j = mid + 1;
    std::vector<int> arr_result;

    // Merge the two sorted halves
    while(i <= mid && j <= h)
    {
        if (arr[i] < arr[j])
        {
            arr_result.push_back(arr[i]);
            i++;
        }
        else
        {
            arr_result.push_back(arr[j]);
            j++;
        }
    }

    // Copy remaining elements from first half
    for(; i <= mid; i++)
    {
        arr_result.push_back(arr[i]);
    }

    // Copy remaining elements from second half
    for(; j <= h; j++)
    {
        arr_result.push_back(arr[j]);
    }

    // Copy back to original array in the correct range
    for(int k = 0; k < arr_result.size(); k++)
    {
        arr[l + k] = arr_result[k];
    }
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
	std::cout<<"Error on function power, return -1"<<std::endl;
	return -1;
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