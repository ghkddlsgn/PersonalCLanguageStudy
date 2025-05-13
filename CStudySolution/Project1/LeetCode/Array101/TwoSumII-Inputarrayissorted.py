from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        head = 0
        tail = len(numbers)-1

        while(head < tail):
            sum = numbers[head] + numbers[tail]
            if sum < target:
                head += 1
            elif sum > target:
                tail -= 1
            else:
                return [head+1, tail+1]
        
        print("logic error")
        return [-1]
