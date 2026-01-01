class Solution:
    def findMin(self, nums: list[int]) -> int:
        l, r = 0, len(nums)-1
        while(l < r):
            m = (l + r)//2
            if nums[m] > nums[-1]:
                l = m + 1
            else:
                r = m
        
        return nums[r]

a = Solution()
min = a.findMin([3,4,5,1,2])
print(min)