class Solution(object):
    def shortestSequence(self, rolls, k):
        """
        :type rolls: List[int]
        :type k: int
        :rtype: int
        """
        have = set()
        count = 1
        for roll in rolls:
            have.add(roll)
            if len(have) == k:
                count += 1
                have.clear()
        return count
        