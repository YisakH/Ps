class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        n = len(nums)    

        # L_end[i]: i에서 끝나는 증가연속 길이
        L_end = [1]*n
        for i in range(1, n):
            if nums[i-1] < nums[i]:
                L_end[i] = L_end[i-1] + 1

        # L_start[i]: i에서 시작하는 증가연속 길이
        L_start = [1]*n
        for i in range(n-2, -1, -1):
            if nums[i] < nums[i+1]:
                L_start[i] = L_start[i+1] + 1

        ans = 0
        for j in range(n-1):  # 경계 j | j+1
            ans = max(ans, min(L_end[j], L_start[j+1]))
        return ans
