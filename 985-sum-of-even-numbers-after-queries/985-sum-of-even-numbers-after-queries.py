class Solution(object):
    def sumEvenAfterQueries(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        summation = 0
        for num in nums:
            if num % 2 == 0:
                summation += num
        answer = []
        for query in queries:
            if nums[query[1]] % 2 == 0:
              summation -= nums[query[1]]
            nums[query[1]] += query[0]
            if nums[query[1]] % 2 == 0:
                summation += nums[query[1]]
            answer.append(summation)
        return answer
        