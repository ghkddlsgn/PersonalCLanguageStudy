class Solution:
    def nextGreatestLetter(self, letters: list[str], target: str) -> str:
        #edge case
        if target <= letters[0] or target >= letters[-1]: return letters[0]
        
        l,r = 0, len(letters)
        while letters[l] <= target:
            m = (l + r)//2
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