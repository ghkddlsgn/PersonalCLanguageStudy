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
    std::vector<int> c = {42, 17, 83};

    cout<<"Begin sort"<<endl;
    printVector(c);
    MergeSortVector_Iterate(c);
    printVector(c);
    cout<<"end programming"<<endl;
    return 0;
}