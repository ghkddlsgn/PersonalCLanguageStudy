from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:            
        hashTable = {}
        
        for i, num in enumerate(nums):
            if num not in hashTable:
                hashTable[num] = 1
            else:
                del hashTable[num]
        
        return list(hashTable.keys())[0]
