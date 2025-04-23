from typing import List

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        totalSum = sum(nums)
        
        #egde case 0:
        if totalSum - nums[0] == 0:
            return 0
        
        chunkA_Sum = 0
        chunkB_Sum = totalSum - nums[0]

        for i in range(1, len(nums)-1):
            chunkA_Sum += nums[i-1]
            chunkB_Sum -= nums[i]
            if chunkA_Sum == chunkB_Sum:
                return i


        #edge case end:
        if totalSum - nums[-1] == 0:
            return len(nums)-1
        
        return -1

sol = Solution()
a = [-1,-1,1,1,0,0]
print(sol.pivotIndex(a))
