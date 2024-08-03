class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        return True if sorted(arr) == sorted(target) else False