# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        if not root:
            return []
        
        queue = [root]
        ans = []
        
        while queue:
            levelSum = 0
            levelNodes = len(queue)
            len_q = levelNodes
            
            while len_q:
                node = queue.pop(0)
                levelSum += node.val
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)   
                len_q -= 1   
            ans.append(levelSum/levelNodes)
        return ans
