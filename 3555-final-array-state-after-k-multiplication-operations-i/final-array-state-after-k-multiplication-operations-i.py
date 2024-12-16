import heapq

class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        nums = [[n, i] for i, n in enumerate(nums)]

        heapq.heapify(nums)

        for i in range(k):
            n, i = heapq.heappop(nums)
            heapq.heappush(nums, [n*multiplier, i])

        nums.sort(key=lambda x:(x[1], -x[0]))

        return [n for n, i in nums]
