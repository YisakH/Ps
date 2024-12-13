import heapq

class Solution:
    def findScore(self, nums: List[int]) -> int:
        heap = [(n, i) for i, n in enumerate(nums)]
        heapq.heapify(heap)
        answer = 0
        marked = set()
        while heap:
            n, i = heapq.heappop(heap)
            if i not in marked:
                marked.add(i)
                marked.add(max(i - 1, 0))
                marked.add(min(i + 1, len(nums) - 1))
                answer += n
        
        return answer
