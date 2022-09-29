class Solution(object):
    def findClosestElements(self, arr, k, x):
        distance = []
        for value in arr:
            distance.append((abs(x - value) , value))
        distance.sort()
        answer = []
        for i in range(k):
            answer.append(distance[i][1])
        answer.sort()
        return answer