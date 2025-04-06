class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        dp = [(-1, 1) for i in range(len(nums))]
        
        for i in range(len(nums)-1, -1, -1):
            for j in range(i + 1, len(nums)):
                if nums[j] % nums[i] == 0 and dp[i][1] < dp[j][1] + 1:
                    dp[i] = (j, dp[j][1] + 1)
        
        max_idx = 0
        for i in range(len(nums)):
            if dp[max_idx][1] < dp[i][1]:
                max_idx = i
        
        ans = [nums[max_idx]]

        while dp[max_idx][0] > 0:
            max_idx = dp[max_idx][0]
            ans.append(nums[max_idx])

        return ans