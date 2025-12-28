# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        upper:int = n
        lower:int = 1
        
        while(1):
            mid = (upper + lower) // 2
            flag:int = guess(mid)
            if flag == 0: return mid
            elif flag == -1: upper = mid - 1
            else: lower = mid + 1
        
        