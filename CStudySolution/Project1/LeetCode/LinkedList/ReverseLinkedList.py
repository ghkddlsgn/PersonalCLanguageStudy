from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        
        newHead = head
        
        while(head.next):
            nextNode = head.next
            nextnextNode = None
            if (head.next.next):
                nextnextNode = head.next.next
            
            #move next node to start
            nextNode.next = newHead
            newHead = nextNode

            #fix head to point nextnextNode
            head.next = nextnextNode
        
        return newHead
