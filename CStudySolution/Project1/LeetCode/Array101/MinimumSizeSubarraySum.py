from typing import List

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        bestWindowLength = 1000000000
        bestTotalSum = 1000000000
        
        curWindowIdx = 0
        curWindowLength = 0
        curTotalSum = 0

        for i in range(0, len(nums)):
            curTotalSum += nums[i]
            curWindowLength += 1

            if curTotalSum < target:
                continue
            
            #shrink window to right as much as possible
            while(curTotalSum - nums[curWindowIdx] >= target):
                curTotalSum -= nums[curWindowIdx]
                curWindowLength -= 1
                curWindowIdx += 1
            
            if (curWindowLength < bestWindowLength):
                bestWindowLength = curWindowLength
                bestTotalSum = curTotalSum
        
        if bestWindowLength == 1000000000: return 0
        return bestWindowLength
