#pragma once
#include <iostream>
#include <vector>

#ifndef SORT_ALGORITHM_H
#define SORT_ALGORITHM_H

template <typename T>
inline void SimpleSwap(T* a, T* b);

void SelectSort(int arr[], int length, bool MinToMax);

void PrintIntArray(int arr[], int length);

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
#endif // !SORT_ALGORITHM_H
