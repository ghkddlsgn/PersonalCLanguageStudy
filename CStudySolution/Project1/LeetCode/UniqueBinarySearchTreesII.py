from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        if n == 0:
            return []
            
        Memory = [[] for _ in range(n+1)]
        Memory[0].append(None)
        Memory[1].append(TreeNode(1))

        def update(CurrentN : int):

            for left_child_index in range(0,n+1):
                new_head = TreeNode(n)
                
                left_total_variation = len(Memory[left_child_index])
                right_total_variation = len(Memory[n-left_child_index])

                for current_left_variation in range(0, left_total_variation):
                    for current_right_variation in range(0, right_total_variation):
                        new_head.left = Memory[left_child_index][current_left_variation]
                        new_head.right = Memory[n-left_child_index][current_right_variation]
                        Memory[n].append(new_head)
            
            return
        
        update(n)

        return Memory[n]