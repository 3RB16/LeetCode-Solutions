class Solution(object):
    def smallestEvenMultiple(self, n):
        for i in range(1 , 5000):
            if i % n == 0 and i % 2 == 0:
                return i
        return 0