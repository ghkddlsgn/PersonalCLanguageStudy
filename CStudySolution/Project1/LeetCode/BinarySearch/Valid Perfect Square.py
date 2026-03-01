class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        l,r = 1, num
        
        while l <= r:
            m = (l + r) // 2
            m_sqare = m * m
            if m_sqare == num: return True
            elif m_sqare < num:
                l = m + 1
            else:
                #m_sqare > num
                r = m - 1
        
        return False
