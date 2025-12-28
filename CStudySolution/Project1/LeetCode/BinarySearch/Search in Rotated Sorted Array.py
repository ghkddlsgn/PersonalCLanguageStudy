class Solution:
    def search(self, nums: list[int], target: int) -> int:
        chunk1_last_idx:int = 0
        chunk2_first_idx:int = len(nums)

        #try to find last idx of chunk 1
        left, right = 1, len(nums)
        while(left <= right):
            #if mid is in chunk 1?
            mid = (left + right)//2
            if nums[mid-1] <= nums[-1]: 
                right = mid -1            
            else: #is in chunk 2?
                mid = left + 1

                
        
        chunk1_last_idx = mid - 1 #if there's no chunk 1, then this will be -1
        chunk2_first_idx = mid

        if target <= nums[-1]: #is target should be in chunk 2?
            return self.binary_search(target, chunk2_first_idx, len(nums) -1)
        else: #target in chunk 1
            if chunk1_last_idx == -1:return -1
            return self.binary_search(target, 0, chunk1_last_idx)
    
    def binary_search(self, target:int, from_idx:int, to_idx) ->int: