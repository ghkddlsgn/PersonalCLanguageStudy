from typing import List

class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        even_index = 0
        odd_index = len(nums)-1

        while(even_index < odd_index):
            if nums[even_index] % 2 == 1: #odd num?
                while(even_index < odd_index):
                    if nums[odd_index] % 2 == 0: #find even num
                        nums[even_index], nums[odd_index] = nums[odd_index], nums[even_index]
                        odd_index -= 1
                        break
                    else:
                        odd_index -= 1
            even_index += 1
        
        return nums

a = Solution()
print(a.sortArrayByParity([3,1,2,4]))
