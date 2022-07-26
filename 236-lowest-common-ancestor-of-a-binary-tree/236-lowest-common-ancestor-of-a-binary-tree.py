# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        
      def dfs(node):
        if not node:
            return
        if node == p or node == q:
           return node
        left_subtree = dfs(node.left)
        right_subtree = dfs(node.right)
        if left_subtree and right_subtree:
           return node
        return right_subtree or left_subtree
        
      return dfs(root)