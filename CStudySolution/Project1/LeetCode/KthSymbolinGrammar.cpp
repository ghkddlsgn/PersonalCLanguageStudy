#include <iostream>
#include <vector>
#include <bitset>

class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 0)
        {
            return 0;
        }
        int size = (1 << n-1);
        int inverse_idx = size-k+1; //it counts from right. starts from 1
        if (inverse_idx == 0)
        {
            return 0;
        }
        return recursive(inverse_idx) % 2 == 0 ? 0 : 1; //even : odd
    }

    int recursive(int inverse_idx) //how many times it switch?
    {
        if (inverse_idx == 1)   return 0;
        if (inverse_idx <= 0)   return -1; //error

        //inverse_idx should be lower of this value
        int max_2pow_value = 1; 
        int max_2pow_exp = 0;
        
        while(inverse_idx > max_2pow_value) //find the minimum 2 power value that larger then idx
        {
            max_2pow_value *= 2;
            max_2pow_exp++;
        }

        int gap = max_2pow_value - inverse_idx;
        
        return gap == 0 ? max_2pow_exp : max_2pow_exp + recursive(gap);
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

#include <math.h>
class Solution2 {
public:
    int recursion(int n, int k) {
        // First row will only have one symbol '0'.
        if (n == 1) {
            return 0;
        }

        int totalElements = pow(2, (n - 1));
        int halfElements = totalElements / 2;

        // If the target is present in the right half, we switch to the respective left half symbol.
        if (k > halfElements) {
            return 1 - kthGrammar(n, k - halfElements);
        }

        // Otherwise, we switch to the previous row.
        return recursion(n - 1, k);
    }

    int kthGrammar(int n, int k) {
        return recursion(n, k);
    };