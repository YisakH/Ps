import heapq

class Solution:
    def findScore(self, nums: List[int]) -> int:
        heap = [(n, i) for i, n in enumerate(nums)]
        heapq.heapify(heap)
        answer = 0
        marked = [ False for _ in nums]
        while heap:
            n, i = heapq.heappop(heap)
            if not marked[i]:
                marked[i] = True
                marked[max(i - 1, 0)] = True
                marked[min(i + 1, len(nums) - 1)] = True
                answer += n
        
        return answer
