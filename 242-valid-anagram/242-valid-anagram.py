class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        frequency = {}
        for item in s:
            frequency[item] = frequency.get(item , 0) + 1;
        for item in t:
            frequency[item] = frequency.get(item , 0) - 1;
        return all(item == 0 for item in frequency.values())