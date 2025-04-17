from typing import Optional

# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Optional[Node]' = None, random: 'Optional[Node]' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head == None:
            return None

        #dict {randomNode : (index)} <- working as hash table
        originalNodeDict = {}
        originalRandomKey = []
        copiedNodeList = []

        #fill the originalNodeMap
        currentNode = head
        currentIndex = 0
        while(currentNode):
            originalNodeDict[currentNode] = currentIndex

            #make new list
            copiedNodeList.append(Node(currentNode.val, None))
            #prepare for next iteration
            currentNode = currentNode.next
            currentIndex += 1
        
        #fill the originalRandomKey
        for element in originalNodeDict:
            if element.random:
                originalRandomKey.append(originalNodeDict[element.random])
            else:
                originalRandomKey.append(-1)
        
        #link each node
        for i in range(len(copiedNodeList)-1):
            copiedNodeList[i].next = copiedNodeList[i+1]
        
        #link random
        for i in range(len(copiedNodeList)):
            randomIndex = originalRandomKey[i]
            if randomIndex != -1:
                copiedNodeList[i].random = copiedNodeList[randomIndex]

        return copiedNodeList[0]
