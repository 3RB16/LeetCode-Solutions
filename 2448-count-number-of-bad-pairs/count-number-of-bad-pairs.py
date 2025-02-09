from typing import List
from collections import defaultdict

class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        """
           all pairs = n * (n - 1) / 2 
           good pairs = (j - i) == (nums[j] - nums[i])
           i know i and nums[i] so .. 
           i - nums[i] == nums[j] - j

           bad_pairs = all_pairs - good_pairs
        """
        n = len(nums)
        freq = defaultdict(int)
        
        # Count frequencies of i - nums[i]
        for index, value in enumerate(nums):
            freq[index - value] += 1
        
        all_pairs = n * (n - 1) // 2
        good_pairs = sum(count * (count - 1) // 2 for count in freq.values())

        bad_pairs = all_pairs - good_pairs
        return bad_pairs
