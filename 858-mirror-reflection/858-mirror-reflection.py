class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:  
        while p & 1 == 0 and q & 1 == 0:
            p >>= 1
            q >>= 1
        if p & 1 == 0:
            return 2
        elif q & 1 == 0:
            return 0
        else:
            return 1