class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':

        cur_value = root.val
        
        if p.val > cur_value and q.val > cur_value:
            return self.lowestCommonAncestor( root.right, p, q)
        
        elif p.val < cur_value and q.val < cur_value:
            return self.lowestCommonAncestor( root.left, p, q)
        
        else:
            return root
