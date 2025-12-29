class Solution:
    def search(self, nums: list[int], target: int) -> int:
        #exception1 : nums len = 1,2
        #exception2 : there's no chunk1
        #exception3 : target is not exist on nums
        chunk2_first_idx:int = -1
        
        #find chunk2's first elem
        left:int = 0
        right:int = len(nums) -1
        mid:int = (left + right)//2
        while(left != right):
            if nums[mid] > nums[-1]: #am i in chunk 1?
                left = mid + 1
            else: #am i in chunk2?
                right = mid    
            mid = (left + right)//2
        
        chunk2_first_idx = mid

        #target is in chunk2?
        if target <= nums[-1]:
            return self.binary_search(chunk2_first_idx, len(nums)-1, nums, target)
        elif chunk2_first_idx != 0: #chunk1 exist?
            return self.binary_search(0, chunk2_first_idx-1, nums, target)        
        else:
            return -1
    
    def binary_search(self, from_idx:int, to_idx:int, nums:list[int], target:int) -> int:
        left = from_idx
        right = to_idx
        mid = (left + right)//2
        while(left <= right):
            if nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid -1
            else:
                return mid
            mid = (left + right)//2


        return -1

