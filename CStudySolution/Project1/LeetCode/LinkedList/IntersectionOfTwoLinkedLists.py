from typing import Optional

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        node_a = headA
        node_b = headB

        size_a = 0
        size_b = 0

        #get length of each linked list
        while(node_a):
            size_a += 1
            node_a = node_a.next
        
        while(node_b):
            size_b += 1
            node_b = node_b.next
        

        smaller_list = (0, ListNode())
        larger_list = (0, ListNode())
        # Determine which list is smaller and which is larger
        
        node_a = headA
        node_b = headB
        if size_a > size_b:
            smaller_list = [size_b, node_b]
            larger_list = [size_a, node_a]
        else:
            smaller_list = [size_a, node_a]
            larger_list = [size_b, node_b]
        #push larger_node to largerlist[size_gap]
        size_gap = larger_list[0] - smaller_list[0]
        for _ in range(size_gap):
            larger_list[1] = larger_list[1].next
        
        result = None
        while(smaller_list[1] and larger_list[1]):
            #if we found intersection node, return that node
            if smaller_list[1] == larger_list[1]:
                return smaller_list[1]
            #if not, move to next node
            smaller_list[1] = smaller_list[1].next
            larger_list[1] = larger_list[1].next

        return None