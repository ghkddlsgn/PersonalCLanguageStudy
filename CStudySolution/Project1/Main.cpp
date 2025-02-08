#include "Main.h"
#include <iostream>
#include "DataStructure\Tree\InhuHeap.h"
#include "SortAlgorithm.h"

using namespace std;

int main()
{
    cout<<"begin programming"<<endl;
    int a[] = {1,3,5,2};

    for(int i = 0; i < 4; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    InsertSort(a, 4, true);
    for(int i = 0; i < 4; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout<<"end programming"<<endl;
    return 0;
}