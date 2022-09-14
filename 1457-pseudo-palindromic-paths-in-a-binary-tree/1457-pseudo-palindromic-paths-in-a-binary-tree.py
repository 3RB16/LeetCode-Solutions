# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def pseudoPalindromicPaths (self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        from collections import Counter
        count = Counter()
        answer = 0
        def check_palindrom():
            is_palindrom = 0
            for i in count.keys():
                if count[i] % 2 == 1:
                    is_palindrom += 1
            return is_palindrom <= 1
        
        def paths(node):
            nonlocal answer
            if node is None:
                return 
            count[node.val] += 1
            if node.right is None and node.left is None:
               if check_palindrom():
                 answer += 1
            else:  
               paths(node.left)
               paths(node.right)
            count[node.val] -= 1
            
        paths(root)
        return answer
        