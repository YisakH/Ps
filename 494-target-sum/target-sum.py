from collections import defaultdict

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        dp = [defaultdict(int) for _ in range(len(nums))]

        dp[0][nums[0]] += 1
        dp[0][-nums[0]] += 1

        for i in range(len(nums)-1):
            keys = list(dp[i].keys())

            for key in keys:
                dp[i+1][key + nums[i+1]] += dp[i][key]
                dp[i+1][key - nums[i+1]] += dp[i][key]
        
        return dp[len(nums) - 1][target]