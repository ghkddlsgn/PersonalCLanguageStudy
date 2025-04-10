from typing import Optional

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        node_a = headA
        node_b = headB

        a_size = 0
        b_size = 0

        while(node_a):
            a_size += 1
            node_a = node_a.next
        
        while(node_b):
            b_size += 1
            node_b = node_b.next
        
        smaller_size = 0
        larger_size = 0

        if (a_size > b_size):
            
            
        
        return None
