class Solution:
    def nextGreatestLetter(self, letters: list[str], target: str) -> str:
        if letters[0] > target or letters[-1] <= target:
            return letters[0]
        
        l,r = 0, len(letters) - 1
        while(l < r):
            m = (l + r) // 2
            if letters[m] <= target:
                l = m + 1
            else:
                r = m
        
        return letters[l]



print(Solution().nextGreatestLetter(["c","f","j"], "c"))  # Output: f
print(Solution().nextGreatestLetter(["c","f","j"], "f"))  # Output: j
print(Solution().nextGreatestLetter(["c","f","j"], "j"))  # Output: c
print(Solution().nextGreatestLetter(["c","f","j"], "a"))  # Output: c
print(Solution().nextGreatestLetter(["c","f","j"], "k"))  # Output: c





# target 
# 111223344455
# l    m     r
# l m r
#    lr
#    m
#   rl

# 00115577

# target 1
# 6666777889
# l        r

# 111111111111111

