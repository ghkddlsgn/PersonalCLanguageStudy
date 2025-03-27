#include <iostream>
#include <vector>
#include <bitset>

class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n = 0)
        {
            return 0;
        }
        int size = (1 << n);
        int inverse_idx = size-k+1; //it counts from right. starts from 1
        if (inverse_idx == 0)
        {
            return 0;
        }
        recursive(inverse_idx);
    }

    int recursive(int inverse_idx)
    {
        if (inverse_idx <= 1)
        {
            return 0;
        }
        int max_2pow_value = 1; //inverse_idx should be lower of this value
        int max_2pow_exp = 0;
        while(inverse_idx >= max_2pow_value) //find the minimum 2 power value that larger then idx
        {
            max_2pow_value *= 2;
            max_2pow_exp++;
        }

        int gap = max_2pow_value - inverse_idx;
        if (gap = 0)
        {
            return max_2pow_exp;
        }
        else
        {
            return max_2pow_exp + recursive(gap);
        }
    }
    
    void printBinary(int n)
    {
        int value = recursive(n);
        int size = 1 << (n-1); // 2^(n-1)
        std::cout << "Binary representation for n=" << n << ": ";
        std::cout << std::bitset<1024>(value).to_string().substr(1024 - size) << std::endl;
    }
};