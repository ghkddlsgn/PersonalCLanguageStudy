from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        i = len(digits) - 1
        while(1):
            if digits[i] != 9:
                digits[i] += 1
                break
            else:
                digits[i] = 0
                if i - 1 >= 0:
                    i = i - 1
                else:
                    digits.insert(1,0)
        
        return digits
