#include "Project1/LeetCode/KthSymbolinGrammar.cpp"
#include <iostream>
using namespace std;

int main()
{
    Solution a;
    int exp = 1;
    for (int i = 1; i < 10; i++)
    {
        a.printBinary(i);
    }
    a.printBinary(3);
    cout<<a.recursive(3);
    return 0;
}