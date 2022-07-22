class Solution(object):
    def isPowerOfTwo(self, n):
      for bit in range(0 , 32):
        if(1 << bit == n):
         return True
      return False
        