from itertools import combinations

class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        ans = 0

        for i in range(1, len(nums) + 1):
            combi = combinations(nums, i)
            for arr in combi:
                res = 0
                for num in arr:
                    res ^= num
                
                ans += res
        
        return ans
            