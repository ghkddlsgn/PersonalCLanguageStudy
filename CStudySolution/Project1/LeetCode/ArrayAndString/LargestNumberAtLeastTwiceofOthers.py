from typing import List

class Solution:
    def dominantIndex(self, nums: List[int]) -> int:

        max = -1000
        maxidx = -1
        max_2 = -1000
        for i in range(len(nums)):
            if max < nums[i]:
                max_2 = max
                max = nums[i]
                maxidx = i
            elif max_2 < nums[i] < max:
                max_2 = nums[i]
        
        if max >= max_2*2:
            return maxidx
        
        return -1

sol = Solution()
a = [3,6,1,0]
print(sol.dominantIndex(a))