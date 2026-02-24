class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        if len(nums) == 0: return [-1,-1]
        pivot = self.binary_find_target_idx(nums, target)
        if pivot == -1: return [-1,-1]         #there's no target?
        left_edge = self.binary_find_left_edge_idx(nums, pivot)
        right_edge = self.binary_find_right_edge_idx(nums, pivot)
        return [left_edge, right_edge]
    
    def binary_find_target_idx(self, nums:list[int], target:int) -> int:
        l,r = 0, len(nums) - 1
        while(l <= r): #find target
            m = (l + r) // 2
            if nums[m] < target:
                l = m + 1
            elif nums[m] > target:
                r = m - 1
            else: #find pivot
                return m            
        return -1
    
    def binary_find_left_edge_idx(self, nums:list[int], pivot:int) -> int:
        if pivot == 0: return 0

        target = nums[pivot]
        l,r = 0,pivot - 1
        while(l <= r):
            if nums[r + 1] == target and nums[r] != target: return r + 1
            m = (l + r) // 2
            if nums[m] < target:
                l = m + 1
            else:
                r = m - 1
        
        print("logic issue:binary_find_left_edge_idx")
        return -1
    
    def binary_find_right_edge_idx(self, nums:list[int], pivot:int) -> int:
        if pivot == len(nums) - 1: return pivot
        
        target = nums[pivot]
        l,r = pivot + 1, len(nums) - 1
        while(l <= r):
            if nums[l - 1] == target and nums[l+1] != target: return l
            m = (l + r) // 2
            if nums[m] > target:
                r = m - 1
            else:
                l = m + 1
        
        print("logic issue:binary_find_right_edge_idx")
        return -1

s = Solution()
print(s.searchRange([5,7,7,8,8,10], 8)) # Output: [3,4]
print(s.searchRange([5,7,7,8,8,10], 6)) # Output: [-1,-1]
print(s.searchRange([], 0)) # Output: [-1,-1]