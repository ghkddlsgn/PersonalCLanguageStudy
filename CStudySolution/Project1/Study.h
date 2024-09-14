#pragma once
#include "CommonClass/InhuLinkedList.h"
#include <iostream>

using namespace std;

int main()
{
    InhuLinkedList A;
    for (int i = 0; i<10; i++)
    {
        A.AddNewLink(i);
    }
    
    A.PrintList();
    A.RemoveTargetValue(9);
    A.RemoveTargetValue(10);
    A.RemoveTargetValue(11);
    A.PrintList();
    
    return 0;
}