class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:        
        
            


s = Solution()
print(s.searchRange([5,7,7,8,8,10], 8)) # Output: [3,4]
print(s.searchRange([5,7,7,8,8,10], 6)) # Output: [-1,-1]
print(s.searchRange([], 0)) # Output: [-1,-1]