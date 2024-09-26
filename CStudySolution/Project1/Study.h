#pragma once

#include <iostream>

#include "DataStructure/List/InhuCircularList.h"

using namespace std;

int main()
{
    InhuCircularList A(10,20,30,40,50,60);
    A.Insert(0,0);
    A.PrintList();
    return 0;
}