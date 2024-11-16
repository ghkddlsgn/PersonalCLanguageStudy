#pragma once
#include <iostream>
#include <vector>
class LowerTriangularMatrix
{
private:
    std::vector<int> arr;
public:
    LowerTriangularMatrix(){}
    LowerTriangularMatrix(int Value)
    {
        arr.push_back(Value);
    }
    template <typename... Args>
    LowerTriangularMatrix(int Value, Args... args)
    {
        arr.push_back(Value);
        (arr.push_back(args), ...);
    }
    void AddElement(int NewValue)
    {
        arr.push_back(NewValue);
    }
    int Get(int i, int j) const
    {
        if(j > i) //is it tried to search 0?
        {
            return 0;
        }
        return arr[(i*(i+1))/2 + j];
    }

    void Print() const
    {
        int MatrixSize = 1;
        while (arr.size()>((MatrixSize*(MatrixSize+1))/2))
        {
            MatrixSize++;
        }
        for (int i = 0; i < MatrixSize; i++)
        {
            for (int j = 0; j < MatrixSize; j++)
            {
                std::cout<<Get(i,j)<<" ";
            }
            std::cout<<std::endl;
        }
    }
};