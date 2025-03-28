#include <iostream>

class Solution {
public:
    int kthGrammar(int n, int k) {
        return recursive(k) % 2 == 0 ? 0 : 1; //even : odd
    }

    int recursive(int idx) //how many times it switch?
    {
        if (idx <= 1) return 0;
        int b = 0;

        //find a,b value that satisfy 2^(b-1) < idx <= 2^b
        while(idx > 1<<b)
        {
            b++;
        }
        return 1 + recursive(idx - (1<<(b-1)));
    }
    
    void printBinary(int n)
    {
        std::cout<<n<<"th row : ";
        int size = (1<<n-1);
        for(int i = 1; i<=size; i++)
        {
            std::cout<<kthGrammar(n, i);
        }
        std::cout<<std::endl;
    }
};