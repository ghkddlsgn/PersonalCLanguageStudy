from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        zero_num = 0

        for i in range(0, len(nums)):
            if nums[i] == 0:
                zero_num += 1
                continue
            nums[i-zero_num] = nums[i]
        
        for i in range(len(nums)-zero_num, len(nums)):
            nums[i] = 0
