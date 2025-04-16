from collections import defaultdict

class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        l, r = 0, 0
        total_cnt = 0
        N = len(nums)
        ans = 0
        count = defaultdict(int)

        while l <= r < N:
            count[nums[r]] += 1
            total_cnt += count[nums[r]] - 1

            while total_cnt >= k:
                # [l: ] 의 길이 - [l:r-1] 길이
                ans += N - l - (r - 1 - l + 1 )
                total_cnt -= count[nums[l]] - 1
                count[nums[l]] -= 1
                l += 1
            
            r += 1
        
        return ans

