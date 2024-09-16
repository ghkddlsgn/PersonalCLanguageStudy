#pragma once

#include <iostream>

#include "DataStructure/Matrix/DiagonalMatrix.h"
#include "DataStructure/Matrix/LowerTriangularMatrix.h"

using namespace std;

int main()
{
    LowerTriangularMatrix A;

    for (int i = 0; i<15; i++)
    {
        A.AddElement(i);
    }
    A.Print();
    return 0;
}

