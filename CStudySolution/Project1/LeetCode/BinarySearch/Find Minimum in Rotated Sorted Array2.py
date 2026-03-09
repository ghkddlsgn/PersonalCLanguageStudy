class Solution:
    def findMin(self, nums: list[int]) -> int:
        if len(nums) == 1 or nums[0] < nums[-1]:
            return nums[0]

        l,r = 0, len(nums)-1
        while(l < r):
            m = (l + r) // 2
            if nums[m] >= nums[0]: #chunk1?
                l = m + 1
            else:
                r = m
        return nums[r]
            
# 45 1234
# l  m  r
#  m r
#45
#lr

test = Solution()
# print(test.findMin([11,13,15,17]))
# print(test.findMin([4, 5, 6, 7, 0, 1, 2]))
# print(test.findMin([3,4,5,1,2]))
print(test.findMin([2,1]))