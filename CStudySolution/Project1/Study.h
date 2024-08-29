#pragma once
#include <iostream>
#include <vector>
#include "SortAlgorithm.h"


int main()
{
    std::vector<int> arr1, arr2;
    for (int i = 0; i<=10; i++)
    {
        arr1.push_back(FibWithRecursion(i));
    }
    PrintVector(arr1);

    for (int i = 0; i<10; i++)
    {
        arr2.push_back(FibWithLoop(i));
    }
    PrintVector(arr2);
    return 0;
}