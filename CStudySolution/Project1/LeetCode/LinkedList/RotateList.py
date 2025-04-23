from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if k == 0 or not head: return head

        length = 0

        cur = head
        while(cur):
            length += 1
            chunkB_Tail = cur
            cur = cur.next
        
        k = k % length
        if k == 0: return head
        


        cur = head
        for _ in range(length-k-1):
            cur = cur.next
        
        chunkA_Tail = cur
        chunkB_Head = cur.next

        chunkA_Tail.next = None
        chunkB_Tail.next = head

        return chunkB_Head