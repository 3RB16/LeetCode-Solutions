# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def pruneTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """
        def construct_tree(root):
            if not root:
                return None 
            root.left = construct_tree(root.left)
            root.right = construct_tree(root.right)
            if root.val == 0 and not root.left and not root.right:
                return None
            return root
        
        return construct_tree(root)