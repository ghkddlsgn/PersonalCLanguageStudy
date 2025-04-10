from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        
        Dummy = ListNode(0)
        Dummy.next = head
        Node_tail = head

        for _ in range(0, n-1):
            Node_tail = Node_tail.next

        Node_front = head
        beforefrontNode = Dummy

        while(Node_tail.next):
            Node_tail = Node_tail.next
            beforefrontNode = Node_front
            Node_front = Node_front.next
        
        beforefrontNode.next = Node_front.next
        Dummy.next = None

        #edge case : return node should be the head of list
        if Node_front == head:
            return Node_front.next
        
        return head