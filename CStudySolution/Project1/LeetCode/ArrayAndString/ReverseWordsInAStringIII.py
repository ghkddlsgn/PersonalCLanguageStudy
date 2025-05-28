class Solution:
    def reverseWords(self, s: str) -> str:
        str_list = list(s)
        def reverse(i:int, j:int):
            while(i<j):
                str_list[i], str_list[j] = str_list[j], str_list[i]
                i += 1
                j -= 1
        
        i = 0
        chunk_start = 0
        for i, char in enumerate(str_list):
            if char == ' ':
                reverse(chunk_start, i-1)
                chunk_start = i+1

        #edge case : last word
        reverse(chunk_start, len(str_list)-1)

        return ''.join(str_list)

a = Solution()
print(a.reverseWords("Let's take LeetCode contest"))