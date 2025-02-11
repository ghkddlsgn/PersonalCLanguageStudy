#pragma once
#include <iostream>
#include <vector>

template <typename T>
inline void SimpleSwap(T& a, T& b);


void BubbleSort(int arr[], int length, bool MinToMax = true);
void InsertSort(int arr[], int length, bool MinToMax = true);
void SelectSort(int arr[], int length, bool MinToMax = true);

void InsertSortVector(std::vector<int>& arr, bool MinToMax = true);
void SelectSortVector(std::vector<int>& arr, bool MinToMax = true);
void QuickSortVector(std::vector<int>& arr, int Range_L = 0, int Range_R = -1);

void PrintIntArray(int arr[], int length);

int factorial(int n);

int power(int Basement, int exponential);

int FibWithLoop(int n);
int FibWithRecursion(int n);

void Hanoi(int DiskNum, int Pillar_From, int Pillar_Target, int Pillar_Auxilary);

template <typename T>
void PrintVector(std::vector<T> ref)
{
    std::cout<<"Vector elements : ";
    for(int i = 0; i<ref.size(); i++)
    {
        std::cout<<ref.at(i)<<" ";     
    }
    std::cout<<std::endl;
}