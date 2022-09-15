class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        changed.sort()
        seen = Counter(changed)
        answer = []
        for value in changed:
            if seen[value] == 0:
                continue
            answer.append(value)
            seen[value] -= 1
            seen[2 * value] -= 1
        if len(answer) * 2 != len(changed):
            answer = []
        return answer