from typing import Optional


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head or not head.next :
            return False

        slow = head
        fast = head.next

        while(slow != fast):
            if not fast.next:
                return False
            if not fast.next.next:
                return False
            
            slow = slow.next #fast will cover every element first, so we don't need to check slow.next is null or not
            fast = fast.next.next
        
        return True
