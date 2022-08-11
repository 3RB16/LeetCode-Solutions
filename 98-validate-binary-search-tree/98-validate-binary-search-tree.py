# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
         def dfs(root , minimum_value , maximum_value):
            if not root:
                return True
            if root.val <= minimum_value or root.val >= maximum_value:
                return False
            return dfs(root.left , minimum_value , root.val) and  dfs(root.right , root.val , maximum_value)
        
         return dfs(root, -math.inf , math.inf)