from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        writer = 0
        for i in range(1,len(nums)):
            if nums[i] > nums[writer]:
                nums[writer+1] = nums[i]
                writer += 1
        return writer + 1