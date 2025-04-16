from typing import Optional
from S_List import ListNode

class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if not head or not head.next:
            return True

        dummy = ListNode()
        dummy.next = head
        slow = dummy
        fast = dummy

        while(fast and fast.next): #check fast is reach at last node
            slow = slow.next
            fast = fast.next.next
        
        #locate slow to 2nd half head
        list_head_1 = head
        list_head_2 = slow.next

        #begin inverse 2nd half list
        pastNode = slow
        currentNode = list_head_2
        
        while(currentNode):
            #save node for next iteration
            nextNode = currentNode.next
            #inverse node
            currentNode.next = pastNode
            
            #set variable for next
            pastNode = currentNode
            currentNode = nextNode
        
        #update list_head_2
        list_head_2.next = None #set tail node's next as none
        list_head_2 = pastNode

        while(list_head_1 and list_head_2):
            if list_head_1.val != list_head_2.val:
                return False
            list_head_1 = list_head_1.next
            list_head_2 = list_head_2.next
        
        return True
