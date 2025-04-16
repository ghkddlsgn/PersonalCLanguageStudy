from typing import Optional


# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child

class Solution:
    def flatten(self, head: 'Optional[Node]') -> 'Optional[Node]':
        def recurse(newHead:Node):
            currentNode = newHead
            
            #sweep to the end of the list
            while(1):
                #has child?
                if currentNode.child:
                    #save adjacent nodes
                    newLayerHead = currentNode.child
                    nextNode = currentNode.next
                    
                    #concatrate head part
                    currentNode.next = newLayerHead
                    newLayerHead.prev = currentNode
                    currentNode.child = None
                    
                    newLayerTail = recurse(newLayerHead)

                    #concatrate tail part
                    if nextNode and newLayerTail:
                        newLayerTail.next = nextNode
                        nextNode.prev = newLayerTail
                
                #if at the tail of current layer, return tail
                if not currentNode.next:
                    return currentNode
                
                currentNode = currentNode.next

        if not head: return None
        recurse(head)
        return head
