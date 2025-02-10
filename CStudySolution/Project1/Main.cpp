#include "Main.h"
#include <iostream>
#include "DataStructure\Tree\InhuHeap.h"
#include "SortAlgorithm.h"

using namespace std;

int main()
{
    cout<<"begin programming"<<endl;
    const int length = 15;
    int A[] = {67, 23, 89, 12, 45, 34, 78, 90, 55, 11, 22, 33, 44, 66, 99};

    // Print original array
    cout << "Original array: ";
    for(int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    // Sort and print sorted array
    InsertSort(A, length, true);
    cout << "Sorted array: ";
    for(int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    cout<<"end programming"<<endl;
    return 0;
}