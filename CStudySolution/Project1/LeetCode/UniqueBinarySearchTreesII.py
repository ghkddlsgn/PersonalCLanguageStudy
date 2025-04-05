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

        # memoization = [ [] for _ in range(0, n+1)]
            
        def recursive(start : int, end : int) -> List[Optional[TreeNode]]:

            if start > end :
                return [None]

            all_trees = []

            for root_val in range(start, end+1):
                #left
                left_subtrees = recursive(start, root_val - 1)
                #right
                right_subtrees = recursive(root_val+1, end)

                for left_subtree in left_subtrees:
                    for right_subtree in right_subtrees:
                        new_tree_node = TreeNode(root_val)
                        new_tree_node.left = left_subtree
                        new_tree_node.right = right_subtree
                        all_trees.append(new_tree_node)
            
            return all_trees
        
        return recursive(1,n)