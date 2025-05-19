from typing import List

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        shortest = []
        sum = 0
        for elem in nums:
            shortest.append(elem)
            sum += elem

            if sum > target:
                closestIdx = [idx for idx in range(len(nums))]
                while len(closestIdx) > 1: #what if there's many satisfied list?
                    nextClosestIdx = []
                    minDist = 1000000000
                    for idx in closestIdx:
                        curdist = sum - shortest[idx]
                        
                        if curdist == minDist:
                            nextClosestIdx.append(idx)
                        elif curdist < minDist:
                            minDist = curdist
                            nextClosestIdx = [idx]

        
        if sum < target:return 0
        
        return len(shortest)

a = Solution()

print(a.minSubArrayLen(7, [2,3,1,2,4,3]))