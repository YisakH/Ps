from heapq import heapify, heappush, heappop

class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extra: int) -> float:
        heap = [(-((p+1)/(t+1) - p/t), p, t) for p, t in classes]
        heapify(heap)

        for _ in range(extra):
            _, p, t = heappop(heap)
            p, t = p + 1, t + 1
            heappush(heap, (-((p+1)/(t+1) - p/t), p, t))

        return sum([p/t for _, p, t in heap]) / len(heap)