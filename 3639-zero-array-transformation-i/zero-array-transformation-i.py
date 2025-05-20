class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        summ = [0 for _ in nums] + [0]
        for l, r in queries:
            summ[l] -= 1
            summ[r + 1] += 1

        for i in range(len(summ) - 1):
            summ[i+1] += summ[i]
        
        for i in range(len(nums)):
            if nums[i] + summ[i] > 0:
                return False
        
        return True