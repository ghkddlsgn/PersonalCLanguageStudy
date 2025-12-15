#include "Project1/LeetCode/Trie/MapSumPairs.h"
#include <iostream>
using namespace std;

int main()
{
    MapSum a;
    a.insert("apple", 3);
    cout << a.sum("ap") << endl;
    a.insert("app", 2);
    
    cout << a.sum("ap") << endl;

    return 0;
}