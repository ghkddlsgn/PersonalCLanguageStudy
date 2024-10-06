#pragma once

#include <iostream>
#include "DataStructure/Queue/InhuCircularQueue.h"

using namespace std;

int main()
{
    InhuCircularQueue A = {10,10,20,30,40,50};
    A.Print();
    A.AddNewElement(123456);
    A.Print();
    A.DeleteElement();
    A.Print();
    return 0;
}