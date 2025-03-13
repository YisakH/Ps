class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        summ = [0 for _ in nums]
        k, i = 0, 0

        while i < len(nums):
            while nums[i] + summ[i] > 0 and k < len(queries):
                l, r, val = queries[k]
                l = max(l, i)

                if l <= r:
                    summ[l] -= val

                    if r < len(nums) - 1:
                        summ[r + 1] += val
                
                k += 1
        
            if i < len(nums) - 1:
                summ[i + 1] += summ[i]
            
            i += 1

        if k < len(queries):
            return k

        for i in range(len(nums)):
            if nums[i] + summ[i] > 0:
                return -1
            
        return k