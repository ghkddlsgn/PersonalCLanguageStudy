#pragma once

#include <iostream>

#include "DataStructure/Matrix/DiagonalMatrix.h"

using namespace std;

int main()
{
    DiagonalMatrix A(10,20,30,40,50,60,70);
    A.Print();
    return 0;
}

