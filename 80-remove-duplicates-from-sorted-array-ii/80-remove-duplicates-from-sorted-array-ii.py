class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        
        for i in nums:
            count_num = nums.count(i)
            if count_num > 2:
                for j in range(count_num - 2):
                    nums.remove(i)
        return len(nums)
