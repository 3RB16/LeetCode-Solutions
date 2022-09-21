class Solution(object):
    def sumEvenAfterQueries(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :retype: List[int]
        """
        summation = 0
        for num in nums:
            if num % 2 == 0:
                summation += num
        answer = []
        for [value , index] in queries:
            if nums[index] % 2 == 0:
                summation -= nums[index]
            nums[index] += value
            if nums[index] % 2 == 0:
                summation += nums[index]
            answer.append(summation)
        return answer
        