from collections import defaultdict

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        res = sum(nums)
        if res % 2 == 1:
            return False
        
        res //= 2
        dp = [False for _ in range(res + 1)]
        dp[0] = True

        for num in nums:
            for j in range(res, num - 1, -1):
                dp[j] = dp[j] or dp[j-num]
    
        return True if dp[res] else False