#pragma once

#include <iostream>

#include "CommonClass/InhuLinkedList.h"

using namespace std;

int main()
{
    InhuLinkedList A{10,20,30,-100,40,50,60,1000,70,80,90};
    A.PrintList();
    A.Insert(0, 0);
    A.Insert(2,222222);
    A.PrintList();
    return 0;
}