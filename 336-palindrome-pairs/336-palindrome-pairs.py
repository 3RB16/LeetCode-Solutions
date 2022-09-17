class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        hashmap = {}
        for i, word in enumerate(words):
            hashmap[word] = i
        answer = set()
        for word in hashmap:
            if len(word) == 0:
                continue
            elif word == word[::-1] and "" in hashmap:
                answer.add((hashmap[word], hashmap[""]))
                answer.add((hashmap[""], hashmap[word]))
            revWord = word[::-1]
            for i in range(len(revWord) - 1, -1, -1):
                rightPart = revWord[i:]
                if rightPart in hashmap and rightPart != word:
                    palindrome = word + rightPart
                    if palindrome == palindrome[::-1]:
                        answer.add((hashmap[word], hashmap[rightPart]))
            for i in range(1, len(revWord) + 1):
                leftPart = revWord[:i]
                if leftPart in hashmap and leftPart != word:
                    palindrome = leftPart + word
                    if palindrome == palindrome[::-1]:
                        answer.add((hashmap[leftPart], hashmap[word]))
        return sorted(answer)
