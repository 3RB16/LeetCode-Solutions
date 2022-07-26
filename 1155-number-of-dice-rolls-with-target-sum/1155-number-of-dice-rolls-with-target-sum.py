class Solution:
    def numRollsToTarget(self, d: int, f: int, target: int) -> int:
        cache = {}
        def solve(d, target):
            if d == 0:
                return 0 if target > 0 else 1
            if (d, target) in cache:
                return cache[(d, target)]
            ret = 0
            for k in range(max(0, target-f), target):
                ret += solve(d - 1, k)
            cache[(d, target)] = ret
            return ret
        return solve(d, target) % (10**9 + 7)
