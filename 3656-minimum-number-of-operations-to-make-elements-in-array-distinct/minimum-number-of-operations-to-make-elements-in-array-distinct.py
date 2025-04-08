from collections import Counter

class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        counter = Counter(nums)

        dupli = 0

        for val in counter.values():
            if val > 1:
                dupli += 1
        
        if dupli == 0:
            return 0
            
        for i, num in enumerate(nums):
            counter[num] -= 1
            if counter[num] == 1:
                dupli -= 1
                if dupli == 0:
                    return i // 3 + 1