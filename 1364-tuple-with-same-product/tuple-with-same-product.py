from collections import defaultdict
import math

class Solution(object):
    def tupleSameProduct(self, nums):
        dictionary = defaultdict(int)

        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                dictionary[nums[i] * nums[j]] += 1
        
        answer = 0
        for val in dictionary.values():
            answer += (2 * val) * 2 * (val - 1)
        
        return answer
            
        