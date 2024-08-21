#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "CommonClass/CustomVector.h"

using namespace  std;

class Solution {
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> ReturnValue;
        ReturnValue.resize(n);

        int Fizz = 1;
        int Buzz = 1;
        
        for (int i = 0; i < n; i++)
        {
            if (Fizz == 3)
            {
                Fizz = 0;
                if (Buzz == 5)
                {
                    Buzz = 0;
                    ReturnValue[i] = "FizzBuzz";
                }
                else
                {
                    ReturnValue[i] = "Fizz";
                }
            }
            else if(Buzz == 5)
            {
                Buzz = 0;
                ReturnValue[i] = "Buzz";
            }
            else
            {
                ReturnValue[i] = to_string(i+1);
            }
            Fizz++;
            Buzz++;
        }
        return ReturnValue;
    }
};

int main()
{
    Solution AAA;
    int n = 15;

    vector<string> StringVector = AAA.fizzBuzz(n);

    PrintElements(StringVector);
    
    return 0;
}