#include <vector>

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;

        int MaxExp = 1;
        int MaxExpLog2 = 0;

        if (n > 0) //n is positive?
        {        
            while(MaxExp * 2 <= n) //init 2 variable
            {
                MaxExp = MaxExp * 2;
                MaxExpLog2++;
            }
        }
        else //n is negative?
        {
            while(MaxExp * 2 <= -n) //init 2 variable
            {
                MaxExp = MaxExp * 2;
                MaxExpLog2++;
            }
        }

        std::vector<double> ValueByExpLog2(MaxExpLog2 + 1, -1); //this array will contain exp2 ABS value of x

        ValueByExpLog2[0] = n > 0 ? x : 1/x;

        for(int i = 1; i<MaxExpLog2 + 1; i++) //fill the array
        {
            ValueByExpLog2[i] = ValueByExpLog2[i-1] * ValueByExpLog2[i-1];
        }
        
        int CurrentExp = MaxExp;
        int CurrentExp_Log2 = 0;
        double ResultValue = ValueByExpLog2[MaxExpLog2];
        
        int RemainExp = n > 0 ? n - MaxExp : (-n) - MaxExp;

        while(RemainExp > 0) //get next max 2 exp
        {
            if (RemainExp < 0) //error check
            {
                return -1;
            }
            CurrentExp = 1; //prepare of find next biggest 2exp value
            CurrentExp_Log2 = 0;
            while(CurrentExp * 2 <= RemainExp) //find out next biggest 2exp value
            {
                CurrentExp = CurrentExp * 2;
                CurrentExp_Log2++;
            }
            ResultValue *= ValueByExpLog2[CurrentExp_Log2]; //add finded out value on result
            RemainExp -= CurrentExp;
        }
        return ResultValue;
    }
};