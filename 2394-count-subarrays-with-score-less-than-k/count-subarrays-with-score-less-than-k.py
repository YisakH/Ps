from collections import deque

class Solution(object):
    def countSubarrays(self, nums, k):
        for i in range(1, len(nums)):
            nums[i] += nums[i-1]
        nums = [0] + nums

        def findEnd(e):
            l, r = 0, e - 1

            while l <= r:
                m = (l + r) // 2
                n = e - m

                if (nums[e] - nums[m]) * n < k:
                    r = m - 1
                elif (nums[e] - nums[m]) * n >= k:
                    l = m + 1

            return l

        cnt = 0
        for e in range(1, len(nums)):
            s = findEnd(e)
            cnt += e - s
        
        return cnt

