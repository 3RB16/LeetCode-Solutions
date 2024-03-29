class Solution:
    def goodNodes(self, root: TreeNode, mx=float('-inf')) -> int:
        if not root: 
            return 0

        if root.val >= mx:
            return 1 + self.goodNodes(root.left, root.val) + self.goodNodes(
                root.right, root.val)
        else:
            return self.goodNodes(root.left, mx) + self.goodNodes(
                root.right, mx)
