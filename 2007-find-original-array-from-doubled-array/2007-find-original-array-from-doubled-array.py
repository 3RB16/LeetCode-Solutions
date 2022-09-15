class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        changed.sort()
        seen = {}
        for value in changed:
            seen[value] = seen.get(value , 0) + 1
        answer = []
        for value in changed:
            if seen[value] == 0:
                continue
            answer.append(value)
            seen[value] = seen.get(value , 0) - 1
            seen[2 * value] = seen.get(2 * value , 0) - 1
        if len(answer) * 2 != len(changed):
            answer = []
        return answer