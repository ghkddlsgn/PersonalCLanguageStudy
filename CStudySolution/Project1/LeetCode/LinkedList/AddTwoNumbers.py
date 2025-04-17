from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        p1 = l1
        p2 = l2
        
        dummy = ListNode()
        currentTail = dummy

        remainValue = 0
        sum = 0

        while(p1 or p2):
            if p1: sum += p1.val
            if p2: sum += p2.val
            
            #handle remainvalue
            sum += remainValue
            remainValue = 0

            if sum >= 10:
                sum %= 10
                remainValue = 1

            new_list = ListNode(sum)
            currentTail.next = new_list
            currentTail = new_list

            if p1: 
                p1 = p1.next
            if p2:
                p2 = p2.next

            sum = 0
        
        #handle edge case
        if remainValue:
            currentTail.next = ListNode(remainValue)
        
        return dummy.next
