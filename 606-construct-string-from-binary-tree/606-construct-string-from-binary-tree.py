# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, root: TreeNode) -> str:
        ans = []
        
        def construct_string(node):
            if node is None:
                return ans
            ans.append(str(node.val))
            if not node.left and node.right:
                ans.append('()')
            if node.left:
                ans.append('(')
                construct_string(node.left)
                ans.append(')')
            if node.right:
                ans.append('(')
                construct_string(node.right)
                ans.append(')')
            return ans
        
        construct_string(root)
        return "".join(ans)
