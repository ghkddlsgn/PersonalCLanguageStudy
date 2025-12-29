# The isBadVersion API is already defined for you.
def isBadVersion(version: int) -> bool:
    pass


class Solution:
    def firstBadVersion(self, n: int) -> int:
        chunk_2_first_elem:int = -1
        left = 1
        right = n
        mid = (left + right)//2
        while(left != right):
            if isBadVersion(mid): #am i in chunk2?
                right = mid
            else:
                left = mid + 1
            mid = (left + right)//2

        
        return mid