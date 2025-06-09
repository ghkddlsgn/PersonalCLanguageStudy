from typing import List

class Solution:
    def isHappy(self, n: int) -> bool:
        squareValueList = [num*num for num in range(10)]
        keyMap = [0] * 10


        def getDigitList(TargetNum:int) -> List[int]:
            result = []
            num = TargetNum
            while num > 0:
                result.append(num%10)
                num = num // 10
            return result
        
        def calcHappyNumSum(TargetNumList : List[int]):            
            nonlocal keyMap
            #add keys to keymap
            for i in TargetNumList:
                keyMap[i] += 1
            
            result = sum(map(lambda x,y: x*y, squareValueList, keyMap))
            keyMap = [0] * 10
            return result
        
        maximumTry = 1000
        currentTry = 0

        #first loop
        currentDigits = getDigitList(n)
        currentSum = calcHappyNumSum(currentDigits)
        seen = {currentSum}
        if currentSum == 1: return True

        while(currentTry <= maximumTry):
            currentTry += 1
            currentDigits = getDigitList(currentSum)
            currentSum = calcHappyNumSum(currentDigits)

            if currentSum == 1:
                return True
            elif currentSum in seen:
                return False
            else:
                seen.add(currentSum)
                
        return False