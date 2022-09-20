class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        queue = deque([root])
        level = 0 
        while queue:
            if level %2:
                l = 0
                r = len(queue) - 1
                while l < r: 
                    queue[l].val,queue[r].val = queue[r].val,queue[l].val
                    l+=1
                    r-=1
            for _ in range(len(queue)):
                node = queue.popleft()
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            level += 1
        return root
