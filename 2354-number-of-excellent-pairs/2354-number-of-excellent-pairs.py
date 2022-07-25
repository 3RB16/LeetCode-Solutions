class Solution:
    def countExcellentPairs(self, nums: List[int], k: int) -> int:
        distinct_elements = set()
        for num in nums:
            distinct_elements.add(num)
         
        def countOnes (num):
            count = 0
            while(num):
                count += 1
                num &= num - 1
            return count
        
        bits = []
        
        for element in distinct_elements:
            bits.append(countOnes(element))
            
        bits.sort()
        answer = 0
        
        for bit in bits:
            firstBit = bisect.bisect_left(bits, k - bit, lo=0, hi=len(bits)) 
            answer += len(bits) - firstBit
            
        return answer
        
       
        