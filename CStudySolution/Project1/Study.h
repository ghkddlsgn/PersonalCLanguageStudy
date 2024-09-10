#pragma once
#include <iostream>
#include <vector>
#include "SortAlgorithm.h"
#include "CommonClass/CustomVector.h"



int main()
{
    CustomVector<int> arr1;
    
    arr1.PushBack(10);
    arr1.PushBack(235);
    arr1.PushBack(11);
    arr1.PushBack(69);
    arr1.PushBack(10);
    arr1.PushBack(2308);
    arr1.PushBack(48);
    arr1.PushBack(89);

    arr1.Sort();
    arr1.Print();

    
    arr1.BinaryTreeSearch(2308);
    
    return 0;
}