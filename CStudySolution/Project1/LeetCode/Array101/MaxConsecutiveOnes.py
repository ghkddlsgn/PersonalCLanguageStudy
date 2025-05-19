from typing import List

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        maxConsecutive = 0
        currentConsecutive = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                maxConsecutive = max(maxConsecutive, currentConsecutive)
                currentConsecutive = 0
            else:
                currentConsecutive += 1

        #edge case : handle last one        
        maxConsecutive = max(maxConsecutive, currentConsecutive)
        return maxConsecutive