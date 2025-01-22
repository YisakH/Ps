from collections import deque

class Solution(object):
    def highestPeak(self, isWater):
        height = [[float('inf') for _ in range(len(isWater[0]))] for _ in range(len(isWater))]
        N, M = len(isWater), len(isWater[0])
        q = deque()

        for i in range(len(isWater)):
            for j in range(len(isWater[0])):
                if isWater[i][j]:
                    q.append((i, j))
                    height[i][j] = 0
        
        visit = set()
        d = ((-1, 0), (1, 0), (0, 1), (0, -1))

        while q:
            y, x = q.popleft()
            if (y, x) in visit:
                continue
            visit.add((y, x))

            for dy, dx in d:
                ny, nx = y + dy, x + dx
                
                if not (0 <= ny < N and 0 <= nx < M):
                    continue
                
                height[ny][nx] = min(height[ny][nx], height[y][x] + 1)

                if (ny, nx) not in visit:
                    q.append((ny, nx))
        
        return height