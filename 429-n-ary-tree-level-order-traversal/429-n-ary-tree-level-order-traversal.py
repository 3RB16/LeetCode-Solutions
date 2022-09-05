"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: Node
        :rtype: List[List[int]]
        """
        queue = []
        ans = []
        if root:
            ans = [[root.val]]
            queue.append(root)

        while len(queue) > 0:
          queue_size = len(queue);
          node_list = []
          while queue_size > 0:
              queue_size -= 1
              node = queue.pop(0)
              for child in node.children:
                    if child.val != None:
                        queue.append(child)
                        node_list.append(child.val)
          if len(node_list) > 0:
            ans.append(node_list)
        return ans
        
        