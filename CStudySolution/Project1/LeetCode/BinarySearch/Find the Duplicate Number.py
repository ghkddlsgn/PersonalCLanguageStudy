class Solution:
    def findDuplicate(self, nums: list[int]) -> int:
        #possible value
        l,r = 1, len(nums)
        while(l < r):
            m = (l + r) // 2
            count = sum(1 for n in nums if n <= m)

            if count <= m: #no duplicated below or equal m
                l = m + 1
            else: #no duplicated above m
                r = m
        
        return l

a = Solution()
nums = [1,2,2,3,4,5,6,7,8]
# nums = [1,2,2,4]
print(a.findDuplicate(nums))





1
2
3
4
5
6
7
8
9