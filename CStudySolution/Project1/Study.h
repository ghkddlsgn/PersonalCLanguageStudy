#pragma once

#include <iostream>

#include "CommonClass/InhuLinkedList.h"

using namespace std;

int main()
{
    InhuLinkedList A{10, 90};
    A.PrintList();
    InhuLinkedList B{1,2,15,78,111};
    B.PrintList();

    A.MergeSortedLinkedList(B);
    A.PrintList();
    B.PrintList();
    
    return 0;
}