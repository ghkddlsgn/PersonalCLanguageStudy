#pragma once
#include <iostream>
#include <vector>
#include "SortAlgorithm.h"
using namespace std;

int PowerWithRecursion(int n, int exponential)
{
    if (exponential==0) return 1;
    if (n<0) //base value nagative check
    {
        cout<<"input negative number in factorial function"<<endl;
        return 0;
    }
    if (1<=exponential) //if exponential is positive
    {
        if (exponential%2 == 1)
        {
            return PowerWithRecursion(n*n, (exponential-1)/2)*n;
        }
        else
        {
            return PowerWithRecursion(n*n, (exponential-2)/2)*n*n;
        }
    }
    return -1;
}

int Power(int n, int exponential)
{
    int ReturnValue = 1;
    for (int i = 0; i < exponential; i++)
    {
         ReturnValue = ReturnValue * n;
    }
    return ReturnValue;
}

int main()
{
    vector<int> arr1, arr2;
    arr1.resize(10);
    arr1.clear();
    arr2.resize(10);
    arr2.clear();
    for (int i = 1; i<=10; i++)
    {
        arr1.push_back(Power(2,i));
    }
    for (int i = 1; i<=10; i++)
    {
        arr2.push_back(PowerWithRecursion(2,i));
    }

    PrintVector(arr1);
    PrintVector(arr2);
    
    return 0;
}