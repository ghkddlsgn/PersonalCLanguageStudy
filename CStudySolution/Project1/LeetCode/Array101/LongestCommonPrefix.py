from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) <= 1:
            return strs[0]
        minlength = min(len(s) for s in strs)

        if minlength == 0: return ""

        #edge case : first char
        char = strs[0][0]
        for j in range(1,len(strs)):
            if char != strs[j][0]:
                return ""

        for i in range(1,minlength):
            char = strs[0][i]
            for j in range(1,len(strs)):
                if char != strs[j][i]:
                    return strs[0][0:i]

        return strs[0][:minlength]

a = Solution()

print(a.longestCommonPrefix(["abb", "ab"]))