#pragma once
#include "Main.h"
#include <iostream>
#include <vector>
#include "Hashing/Chain.h"

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

    HashChain a(1,2,3,4,5,6,7,8,9,10,11,22,33,44,55,66,77,88,99,100);
    a.PrintChainList();
    
    // Test Insert
    a.Insert(15);
    cout << "After inserting 15:" << endl;
    a.PrintChainList();

    a.Delete(15);
    a.Delete(77);
    a.Delete(7);

    a.PrintChainList();
    cout<<"end programming"<<endl;

    return 0;
}