#include <stdio.h>

#ifndef SORT_ALGORITHM_H
#define SORT_ALGORITHM_H

template <typename T>
inline void SimpleSwap(T* a, T* b);

void SelectSort(int arr[], int length, bool MinToMax);

void PrintIntArray(int arr[], int length);

#endif // !SORT_ALGORITHM_H
