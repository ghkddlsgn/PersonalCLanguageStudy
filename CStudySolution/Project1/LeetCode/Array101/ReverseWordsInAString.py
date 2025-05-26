from typing import AnyStr

class Solution:
    def reverseWords(self, s: str) -> str:
        charList = list(s)
        def reverse(idx1:int, idx2:int):
            if idx1 > idx2:
                idx1, idx2 = idx2, idx1
            
            while(idx1 < idx2):
                charList[idx1], charList[idx2] = charList[idx2], charList[idx1] 
                idx1 += 1
                idx2 -= 1

        reverse(0, len(charList)-1)
        
        reader = 0
        writer = 0
        lastchar = 0
        chunkStart = -1
        while reader < len(charList):
            #Is char?
            if charList[reader] != ' ':
                LastCharIdx = writer
                #beginning of chunk?
                if chunkStart == -1:
                    chunkStart = reader
                    reader += 1
                #middle of chunk?
                else:
                    reader += 1
            else:
                # end of chunk?
                if chunkStart != -1:
                    reverse(chunkStart, reader - 1)

                    for i in range(chunkStart, reader):
                        charList[writer] = charList[i]
                        writer  += 1
                    #add space at the end
                    charList[writer] = ' '
                    writer += 1
                    #update for next loop
                    chunkStart = -1
                    reader += 1
                    #update for return
                    lastchar = writer - 2
                else:
                    #if it's meaningless space, just skip
                    reader += 1
        
        #handle edgecase : last chunk without space
        if charList[-1] != ' ':
            reverse(chunkStart, len(charList)-1)
            for i in range(chunkStart, len(charList)):
                charList[writer] = charList[i]
                writer  += 1
            lastchar = writer - 1

        charList = charList[0:lastchar+1]
        return ''.join(charList)
        
a = Solution()
print(a.reverseWords("  hello world  "))
print(len(a.reverseWords("  hello world  ")))
print(a.reverseWords("the sky is blue"))
