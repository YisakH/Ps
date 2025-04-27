class Solution:
    def countSubarrays(self, nums: List[int]) -> int:
        cnt = 0
        for i in range(len(nums) -2):
            f, s, t = nums[i], nums[i+1], nums[i+2]

            if (f + t) * 2 == s:
                cnt += 1
        
        return cnt