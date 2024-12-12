import heapq
from math import sqrt

class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        heap = [-n for n in gifts]
        heapq.heapify(heap)

        for _ in range(k):
            num = - heapq.heappop(heap)
            heapq.heappush(heap, -int(sqrt(num)))
        
        return -sum(heap)
        