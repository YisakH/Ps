from collections import Counter

class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        visit = set()

        for i in range(len(nums) - 1, -1, -1):
            if nums[i] in visit:
                return i // 3 + 1
            
            visit.add(nums[i])
        
        return 0