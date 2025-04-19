from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        def reverseList(head: ListNode, attachTo: ListNode):
            Dummy = ListNode(-1)
            curNode = head
            nextNode = None
            newHead = Dummy

            while(curNode):
                nextNode = curNode.next
                curNode.next = 
            
            head.next = attachTo

        if not head or k <= 0: return head

        ListLength = 0
        currentNode = head

        chunkA_Length = 0
        chunkA_head = head
        chunkA_tail = head
        chunkB_Length = k
        chunkB_head = head
        chunkB_Tail = head
        #i can sure chunkB_length is more then 0

        #get ListLength, chunkB_Tail
        while(currentNode):
            ListLength += 1
            chunkB_Tail = currentNode
            if currentNode.next:
                currentNode = currentNode.next
        
        #get chunkA_Length
        k = k % ListLength
        chunkA_Length = ListLength - k

        #get chunkA_tail, chunkB_head
        currentNode = head
        for _ in range(0, chunkA_Length - 1):
            currentNode = currentNode.next
        chunkA_tail = currentNode
        chunkB_Tail = currentNode.next
        newHead = chunkA_head

        #check there's no chunkA
        if chunkA_Length == 0:
            chunkA_head == None
            chunkA_tail == None
            newHead = head
        
        #reverse chunkB
        for _ in range(chunkB_Length):
            
        