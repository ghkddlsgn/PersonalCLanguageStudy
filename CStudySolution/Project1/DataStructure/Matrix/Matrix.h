#pragma once
#include <iostream>
#include <vector>

class DiagonalMatrix
{
private:
    std::vector<int> Arr;
public:
    DiagonalMatrix(int NewValue)
    {
        Arr.push_back(NewValue);
    }
    template<typename... Args>
    DiagonalMatrix(int a, Args... args)
    {
        Arr.push_back(a);
        (Arr.push_back(args),...);
    }

    int Get(int i, int j)
    {
        if (i==j)
        {
            return Arr[i];
        }
        else
        {
            return 0;
        }
    }

    void Print()
    {
        for (int i = 0; i <Arr.size(); i++)
        {
            for (int j = 0; j <Arr.size(); j++)
            {
                std::cout<<Get(i,j)<<" ";
            }
            std::cout<<std::endl;
        }
    }
};
