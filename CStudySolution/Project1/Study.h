#pragma once

#include <iostream>

#include "CommonClass/InhuLinkedList.h"

using namespace std;

int main()
{
    InhuLinkedList A{10,20,30,-100,40,50,60,1000,70,80,90};
    A.PrintList();
    A.ReverseElements();
    A.PrintList();
    A.AddNewNode(10000);
    A.PrintList();
    return 0;
}