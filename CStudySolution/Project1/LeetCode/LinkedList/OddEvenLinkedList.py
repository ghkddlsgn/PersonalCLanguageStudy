from typing import Optional
from S_List import ListNode

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        oddNode = head
        evenNode = head.next
        evenHead = head.next

        while(evenNode and evenNode.next):
            oddNode.next = oddNode.next.next
            oddNode = oddNode.next

            evenNode.next = evenNode.next.next
            evenNode = evenNode.next
        
        oddNode.next = evenHead

        return head
