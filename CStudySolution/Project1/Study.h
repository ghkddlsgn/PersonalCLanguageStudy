#pragma once
#include <iostream>
#include <vector>
#include "SortAlgorithm.h"
#include "CommonClass/CustomVector.h"



int main()
{
    std::vector<int> arr1 = {1,3,4,5,8,9,12,13,14,17,18,19};

    PrintVector(CheckLinear(arr1));
      
    return 0;
}