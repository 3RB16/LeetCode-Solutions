class Solution(object):
    def isPowerOfThree(self, n):
        for base in range(0 , 32):
         if 3 ** base == n:
           return True
        return False
        