class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        import heapq

        heap = []
        for value in nums:
            heapq.heappush(heap, value)
        
        operations_count = 0
        while len(heap) > 1:
            x = heapq.heappop(heap)
            if x >= k:
                break
            y = heapq.heappop(heap)
            heapq.heappush(heap, min(x, y) * 2 + max(x, y))
            operations_count += 1
        
        return operations_count
