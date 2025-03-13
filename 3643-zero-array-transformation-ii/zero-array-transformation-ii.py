class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:

        def getAnswer(k):
            summ = [0 for _ in nums]

            for l, r, val in queries[:k+1]:
                summ[l] -= val
                if r < len(nums) - 1:
                    summ[r + 1] += val
            
            for i in range(1, len(nums)):
                summ[i] += summ[i-1]
            
            for i in range(len(nums)):
                if nums[i] + summ[i] > 0:
                    return False
            
            return True

        if sum(nums) == 0:
            return 0

        if not getAnswer(len(queries) - 1):
            return -1
        
        if getAnswer(0):
            return 1
        

        
        l, r = 0, len(queries) - 1
        lastVal = False
        while l <= r:
            m = (l + r) // 2

            if getAnswer(m):
                r = m - 1
                lastVal = True
            else:
                l = m + 1
                lastVal = False
            
        return l + 1 if lastVal else l + 1