#pragma once
#include <vector>

static class InhuMath
{
private:
    int* Hashmap;

    std::vector<int> ReturnValue;
public:
    ~InhuMath()
    {
        delete []Hashmap;
    }
    int PrintPermutation(const std::vector<int>& TargetIntArray)
    {
        delete[] Hashmap; //init values
        Hashmap = new int[TargetIntArray.size()];
        for (int A : Hashmap)
        {
            Hashmap[A] = 0;
        }
    }

    std::vector<int> ReturnPermutationArray(const std::vector<int>& TargetIntArray, int sum = 0, int i = 0, int k = 0)
    {
        if (k == TargetIntArray.size()-1) //at the last level?
        {
            ReturnValue.push_back(sum*10 + TargetIntArray[i]); //Add New list on ReturnValue
            if (i == TargetIntArray.size()-1)
            {
                return ReturnValue;
            }
            else
            {
                Hashmap[i] = 1;
                ReturnPermutationArray(TargetIntArray, sum, i+1, k-1);
            }
        }
        
        if(i == TargetIntArray.size()) //if it reached at the end of current depth, move to next depth
        {
            ReturnPermutationArray(TargetIntArray, sum, 0, k + 1);
        }
        else
        {
            if (Hashmap[i] == 0)
            {
                Hashmap[i] = 1;
                ReturnPermutationArray(TargetIntArray, 10*sum + TargetIntArray[i], i, k+1);
            }
            else
            {
                ReturnPermutationArray(TargetIntArray,sum, i+1, k);
            }
        }
    }
};
