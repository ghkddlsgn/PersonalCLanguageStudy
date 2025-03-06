#include "Main.h"
#include <iostream>
#include <vector>
#include "DataStructure/Graph/InhuGraph.h"

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

    InhuGraph a;
    a.Insert_Element(1);
    a.Insert_Element(2);
    a.Insert_Element(3);
    a.Insert_Element(4);
    a.Insert_Element(5);
    a.Insert_Element(6);
    a.Insert_Element(7);
    
    a.Insert_Path(0,5,5);
    a.Insert_Path(0,1,25);
    a.Insert_Path(5,4,20);
    a.Insert_Path(3,4,18);
    a.Insert_Path(6,1,10);
    a.Insert_Path(1,2,12);
    a.Insert_Path(4,3,16);
    a.Insert_Path(6,3,14);
    a.Insert_Path(3,2,8);

    printVector<int>(a.prim_line());

    cout<<"end programming"<<endl;

    return 0;
}