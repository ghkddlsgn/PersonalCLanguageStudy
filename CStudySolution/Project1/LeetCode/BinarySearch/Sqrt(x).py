class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0: return 0
        if x == 1: return 1
        if x <= 4: return x//2
        
        upper:int = x//2
        lower:int = 1
        mid:int = (upper + lower)//2

        while(1):
            mid = (upper + lower)//2
            if (mid)**2 == x: return mid
            if (mid) == lower:return mid
            
            if (mid)**2 < x:
                lower = mid
            else:
                upper = mid


if __name__ == "__main__":
    sol = Solution()
    test_cases = [0, 1, 2, 3, 4, 8, 10, 16, 27, 2147395599]
    for x in test_cases:
        print(f"mySqrt({x}) = {sol.mySqrt(x)}, exp_value = {int(x**0.5)}")
