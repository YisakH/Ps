from heapq import heappush, heappop, heapify

class Solution(object):
    def minOperations(self, nums, k):
        heapify(nums)
        answer = 0

        while nums[0] < k:
            answer += 1
            x = heappop(nums)
            y = heappop(nums)
            heappush(nums, min(x, y) * 2 + max(x, y))

        return answer

        