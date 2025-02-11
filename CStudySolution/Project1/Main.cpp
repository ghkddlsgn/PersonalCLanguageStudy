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
    std::vector<int> a = {23, 45, 12, 67, 89, 34, 56, 78, 90, 11};
    printVector(a);
    cout<<"Begin sort"<<endl;
    QuickSortVector(a);
    printVector(a);
    cout<<"end programming"<<endl;
    return 0;
}