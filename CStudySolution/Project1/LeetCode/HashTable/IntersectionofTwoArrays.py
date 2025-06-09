from typing import List

class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        keyMap = {}
        result = []
        for value in nums1:
            keyMap[value] = [1,0]
        
        for value in nums2:
            if value in keyMap:
                keyMap[value][1] = 1
        
        for key, value in keyMap.items():
            if value[0] == 1 and value[1] == 1:
                result.append(key)
        
        return result
        