# 1 <= haystack.length, needle.length <= 104
# haystack and needle consist of only lowercase English characters.

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        def strcmp(idx_from:int) -> bool:
            #valid check
            if (idx_from + len(needle) - 1) > len(haystack) - 1:
                return False
            
            #strcmp
            for i in range(len(needle)):
                if haystack[idx_from + i] != needle[i]:
                    return False

            return True


        maxidxHey, maxidxNeedle = len(haystack) - 1, len(needle) - 1

        for i in range(0, maxidxHey - maxidxNeedle + 1):
            if haystack[i] == needle[0]:
                #begin str compare
                cmpResult = strcmp(i)
                if cmpResult: #if found, return idx
                    return i

        return -1

a = Solution()

print(a.strStr('sadbutsad','sad'))