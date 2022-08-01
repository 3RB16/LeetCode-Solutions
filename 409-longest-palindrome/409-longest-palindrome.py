class Solution:
    def longestPalindrome(self, s: str) -> int:
        longest_length = 0
        freq = {}
        
        for cur in s:
            freq[cur] = freq.get(cur , 0) + 1
            
        maybe_increase = False
        
        for key , value in freq.items():
            if value & 1 == 1:
                longest_length += (value - 1)
                maybe_increase = True
            else:
                longest_length += (value)
                
        if maybe_increase and longest_length & 1 == 0:
            longest_length += 1
            
        return longest_length
                
        
            