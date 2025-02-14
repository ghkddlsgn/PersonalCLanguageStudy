#pragma once
#include "Main.h"
#include <iostream>
#include <vector>
#include "DataStructure\Tree\InhuHeap.h"
#include "SortAlgorithm.h"

using namespace std;

template<typename T>
void printVector(const std::vector<T>& vec) {
    for(const auto& element : vec) {
        cout << element << " ";
    }
    cout << endl;
}

int main()
{
    cout<<"begin programming"<<endl;
    std::vector<int> a = {7, 9, 11, 23, 45, 56, 78, 90};
    std::vector<int> b = {1, 3, 12, 67, 89, 345};
    std::vector<int> c = {73, 28, 95, 41, 16, 84, 59, 37, 62, 13, 90, 45};
    printVector(c);
    
    cout<<"Begin sort"<<endl;
    for (int i =0; i<c.size(); i++)
    {
        std::vector<int> temp;
        for (int j = 0; j <= i; j++)
        {
            temp.push_back(c[j]);
        }
        MergeSortVector_Iterate(temp);
        printVector(temp);
    }
    cout<<"end programming"<<endl;

    return 0;
}