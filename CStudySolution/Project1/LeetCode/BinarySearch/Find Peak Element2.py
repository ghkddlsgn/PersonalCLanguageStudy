class Solution:
    def findPeakElement(self, nums: list[int]) -> int:
        if len(nums) == 1:return 0
        
        #from here, len >= 2
        l,r = 0, len(nums) - 1

        if nums[l] > nums[l+1]: return l
        if nums[r-1] < nums[r]: return r
        
        while(l <= r):
            m = (l + r) // 2
            if nums[m] < nums[m+1]: #acs?
                l = m
            else: #desc?
                if nums[m-1] < nums[m]: return m #peak?
                r = m
        
        return -12345
                



sol = Solution()
nums = [1,2,1,3,5,6,4]
print("Input:", nums)
print("Peak idx:", sol.findPeakElement(nums))
