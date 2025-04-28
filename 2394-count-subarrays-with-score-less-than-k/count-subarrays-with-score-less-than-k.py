from collections import deque

class Solution(object):
    def countSubarrays(self, nums, k):
        s= 0
        summ = 0
        cnt = 0
        
        for e in range(len(nums)):
            summ += nums[e]

            while summ * (e - s + 1) >= k:
                summ -= nums[s]
                s += 1 
            
            cnt += e - s + 1

        return cnt