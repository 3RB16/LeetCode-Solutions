# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        order = []
        def inorder_traverse(root):
            if not root:
                return 
            inorder_traverse(root.left)
            order.append(root.val)
            inorder_traverse(root.right)
        inorder_traverse(root)
        return order
            