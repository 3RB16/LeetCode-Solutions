class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        freq = {}
        for cur in magazine:
            freq[cur] = freq.get(cur , 0) + 1
        
        for cur in ransomNote:
            freq[cur] = freq.get(cur , 0) - 1
            
        for key , value in freq.items():
            if value < 0:
                return False
        
        return True