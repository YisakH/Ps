from heapq import heappush, heappop

class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        N, M = len(moveTime), len(moveTime[0])
        d = ((-1, 0), (1, 0), (0, -1), (0, 1))
        
        heap = []
        heappush(heap, (0, 0, 0, True)) # ?, ?, ?, is One Sec
        visit = set()

        while heap:
            t, cy, cx, oneSec = heappop(heap)
            
            if (cy, cx) in visit:
                continue

            visit.add((cy, cx))
            
            if (cy, cx) == (N-1, M-1):
                return t

            for dy, dx in d:
                ny, nx = dy + cy, dx + cx

                if not (0 <= ny < N and 0 <= nx < M):
                    continue
                if (ny, nx) in visit:
                    continue

                nt = max(t, moveTime[ny][nx])
                nt += 1 if oneSec else 2
            
                heappush(heap, (nt, ny, nx, not oneSec))

        return -1