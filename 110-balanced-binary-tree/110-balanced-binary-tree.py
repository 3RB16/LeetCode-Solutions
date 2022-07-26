class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if not root: 
            return True
        
        def dfs(root):
            if not root: 
                return 0
            left = dfs(root.left)
            right = dfs(root.right)
            if not (~left) or not (~right) or  abs(left - right) > 1: 
                    return -1
            return 1 + max(left , right)
        
        return ~dfs(root)
