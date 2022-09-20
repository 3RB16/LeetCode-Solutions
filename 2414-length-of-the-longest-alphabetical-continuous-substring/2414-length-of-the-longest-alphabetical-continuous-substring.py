class Solution(object):
    def longestContinuousSubstring(self, s):
        n = len(s)
        begin = 0
        end = 1
        longest = 1
    
        while end < n:
            while (ord(s[end]) - 97) != (ord(s[end - 1]) - 97) + 1 and begin < end:
                begin += 1
            longest = max(longest , end - begin + 1)
            end += 1
        return longest
        