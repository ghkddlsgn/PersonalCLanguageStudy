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
    a.Insert(1);
    a.Insert(2,{1});
    a.Insert(4,{1});
    a.Insert(3,{1,2,4});
    a.Insert(5,{4,3});
    a.Insert(6,{5});
    a.Insert(7,{5});

    printVector<int>(a.Bfs(1));

    cout<<"end programming"<<endl;

    return 0;
}