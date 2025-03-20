#include <vector>

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;

        double returnValue = 1;
        double currentValue;
        int returnExp = 0;
        int currentExp;
        int remainExp = n;

        std::vector<float> cachValue; //it will store x^2n power series value
        int cachIdx = 0;
        int maxCachSize = 0;

        currentExp = n;
        while(currentExp/2 != 0)
        {
            currentExp /= 2;
            maxCachSize++;
        }
        cachValue.reserve(maxCachSize + 1);
        cachValue.push_back(x); //init first value

        if (n > 0)
        {
            currentValue = x;
            currentExp = 1;
            while(remainExp > 0)
            {
                if(remainExp < 0) //error check
                {
                    return -1;
                }
                if (currentExp * 2 <= remainExp) //exp 2 phase
                {
                    
                    currentValue = currentValue * currentValue;
                    currentExp = currentExp * 2;

                    cachValue.push_back(currentValue);

                    continue;
                }
                else //prepare for remain chunk
                {
                    returnValue *= currentValue;
                    returnExp += currentExp;
                    remainExp = n - returnExp;

                    currentValue = x;
                    currentExp = 1;
                    cachIdx = 
                }
            }
        }
        else
        {
            for(int i = n; i<0; i++)
            {
                currentValue = currentValue / x;
            }
        }
        return currentValue;
    }
};