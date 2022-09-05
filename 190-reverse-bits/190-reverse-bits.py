class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
      bits = []
      for i in range(0 , 32):
         if n & (1 << i):
            bits.append(1)
         else:
            bits.append(0)
      bits.reverse()
      value = 0
      for i in range(0 , 32):
        value |= (bits[i] * (1 << i))
        
      return value