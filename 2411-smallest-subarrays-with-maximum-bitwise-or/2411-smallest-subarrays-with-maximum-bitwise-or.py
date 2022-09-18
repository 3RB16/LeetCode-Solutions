class SegTree:

    def __init__(self, nums):
        self.n = n = len(nums)
        self.tree = [0] * (2 * n)
        for i in range(n):
            self.tree[i + n] = nums[i]
        for i in range(n-1, 0, -1):
            self.tree[i] = self.tree[2 * i] | self.tree[2 * i + 1]
        
    def orRange(self, left, right):
        left += self.n
        right += self.n + 1
        orRes = 0
        while left < right:
            if left % 2 == 1:
                orRes |= self.tree[left]
                left += 1
            
            if right % 2 == 1:
                right -= 1
                orRes |= self.tree[right]
                
            left //= 2
            right //= 2
        return orRes

class Solution:
    def smallestSubarrays(self, nums: List[int]) -> List[int]:
        
        segtree = SegTree(nums)
        
        ans = [1] * len(nums)
        l = len(nums) - 1
        r = len(nums) - 1
        
        while l >= 0:

            while r > l and segtree.orRange(l, r-1) == segtree.orRange(l, r):
                r -= 1
                
            ans[l] = r - l + 1
            l -= 1
            
        return ans
