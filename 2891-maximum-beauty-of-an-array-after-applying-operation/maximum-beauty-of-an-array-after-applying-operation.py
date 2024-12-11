class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        nums.sort()
        nums = [[n-k, n+k] for n in nums]
        N = len(nums)
        answer = 0
        l, r = 0, 0

        while l < N:
            while r < N and nums[l][1] >= nums[r][0]:
                r += 1
            r -= 1
            answer = max(answer, r - l + 1)
            l += 1
        
        return answer