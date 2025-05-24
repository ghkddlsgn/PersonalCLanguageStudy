from typing import List

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        def reverse(i,j):
            if i > j: i,j = j,i
            while(i<j):
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
                j -= 1

        k = k % len(nums)
        if k == 0: return

        reverse(0, len(nums)-1)
        reverse(0, k-1)
        reverse(k, len(nums)-1)
