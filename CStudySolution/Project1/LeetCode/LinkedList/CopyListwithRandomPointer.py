from typing import Optional

# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Optional[Node]' = None, random: 'Optional[Node]' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        originalList = []
        originalListPtrIndex = []
        copiedList = []

        #save original list
        currentNode = head
        while(currentNode):
            originalList.append(currentNode)
            originalListPtrIndex.append(-1)
            currentNode = currentNode.next
        
        #save random's index
        currentNode = head
        for i in range(0, len(originalList)):
            if originalList[i].random:
                originalListPtrIndex[i] = originalList.index(originalList[i].random)
        
        #begin copy
        copiedList = [Node(-1) for _ in range(len(originalList))]
        for i in range(0, len(originalList)-1):
            element = copiedList[i]
            element.val = originalList[i].val
            element.next = copiedList[i+1]
            if originalListPtrIndex != -1:
                element.random = copiedList[originalListPtrIndex[i]]
        
        #handle edge(end) case
        element = copiedList[-1]
        element.val = originalList[-1].val
        element.next = None
        if originalListPtrIndex != -1:
            element.random = copiedList[originalListPtrIndex[-1]]

        return copiedList[0]
