#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "CommonClass/CustomVector.h"

using namespace  std;

class Solution {
public:
    int numberOfSteps(int num) {
        return (num & ~0);
    }
};

int main()
{
    Solution AAA;
    
    cout<<AAA.numberOfSteps(14)<<endl;;
    cout<<AAA.numberOfSteps(8)<<endl;
    cout<<AAA.numberOfSteps(123)<<endl;
    
    return 0;
}