from typing import Optional
import S_List

class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        if not head :
            return None
        
        Dummy = ListNode()
        Dummy.next = head

        past_Node = Dummy
        current_Node = head

        while(current_Node.next):
            #delete node from list
            if current_Node.val == val:
                past_Node.next = current_Node.next
            else:
                past_Node = past_Node.next
            current_Node = current_Node.next

        # end of list?
        if current_Node.val == val:
            past_Node.next = None
            
        return Dummy.next
