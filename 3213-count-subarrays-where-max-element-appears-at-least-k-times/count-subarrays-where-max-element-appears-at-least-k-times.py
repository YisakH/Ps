class Solution(object):
    def countSubarrays(self, nums, k):
        max_val = max(nums)
        cnt = 0
        l = 0
        ans = 0

        for r in range(len(nums)):
            if nums[r] == max_val:
                cnt += 1

            while cnt >= k:
                ans += len(nums) - r
                if nums[l] == max_val:
                    cnt -= 1
                l += 1
        
        return ans
