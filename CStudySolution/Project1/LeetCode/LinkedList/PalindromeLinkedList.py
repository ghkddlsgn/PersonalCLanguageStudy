from typing import Optional
from S_List import ListNode

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if not head: return True
        if not head.next: return True

        dummy = ListNode()
        dummy2 = ListNode()
        dummy.next = head
        dummy2.next = dummy
        
        slow = dummy
        fast = dummy
        pastNode = dummy2

        while(fast.next): #check fast is reach at last node
            #reverse node
            nextNode = slow.next
            slow.next = pastNode
            
            #prepare for next iteration
            fast = fast.next.next
            pastNode = slow
            slow = nextNode
        
        newslow = head
        newfast = nextNode
        while(slow):
            if newfast.val != newslow.val:
                return False
            newslow = newslow.next
            newfast = newfast.next
        
        return True
