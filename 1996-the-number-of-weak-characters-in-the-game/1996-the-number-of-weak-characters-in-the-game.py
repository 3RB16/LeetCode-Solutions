class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        weakCharacters = 0
        maxDefense = 0
        properties.sort(key = lambda x: (-x[0], x[1]))
        for _, defense in properties:
            if defense < maxDefense: 
                weakCharacters += 1
            else: 
                maxDefense = defense
        return weakCharacters
