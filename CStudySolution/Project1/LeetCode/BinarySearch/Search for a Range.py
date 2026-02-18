class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        return [self.searchTarget(nums,target,True), self.searchTarget(nums,target, False)]

        #search target
    def searchTarget(self, nums:list[int], target:int, left_bias:bool):
        l = 0
        r = len(nums) - 1
        edge = -1

        while(l <= r):
            m = (l + r)//2
            if nums[m] < target:
                l = m + 1
            elif nums[m] > target:
                r = m - 1
            else: #inside of target chunk
                edge = m
                if left_bias:
                    r = m - 1
                else:
                    l = m + 1

        return edge

        #search left edge
        #search right edge

        # INSERT_YOUR_CODE

solution = Solution()
nums = [5,7,7,8,8,10]
target = 8
print(solution.searchRange(nums, target))  # Example usage, should print the indices of first and last occurrence of 8
