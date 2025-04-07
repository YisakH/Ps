from collections import defaultdict

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        res = sum(nums)
        if res % 2 == 1:
            return False
        
        res //= 2
        dp = defaultdict(int)
        for num in nums:
            new_keys = [num]
            for key in dp.keys():
                new_keys.append(key + num)
            
            for new_key in new_keys:
                dp[new_key] += 1
        
        return True if dp[res] else False