from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        a = set(nums)
        if len(a) < len(nums):
            return True
        else:
            return False

a = Solution()
print(a.containsDuplicate([1,2,3,1]))