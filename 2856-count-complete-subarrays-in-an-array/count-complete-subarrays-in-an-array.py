from collections import defaultdict

class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        k = len(set(nums))
        count = defaultdict(int)
        distinct = 0
        res = 0
        l = 0

        for r in range(n):
            if count[nums[r]] == 0:
                distinct += 1
            count[nums[r]] += 1

            while distinct == k:
                count[nums[l]] -= 1
                if count[nums[l]] == 0:
                    distinct -= 1
                
                l += 1
            
            res += r - l + 1


        return n * (n + 1) // 2 - res
