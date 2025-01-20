from heapq import heappush, heappop

class Solution(object):
    def minCost(self, grid):
        N = len(grid)
        M = len(grid[0])
        
        heap = []
        heappush(heap, (0, 0, 0)) # dist, i, j
        visited = set()
        d = ((0, 1), (0, -1), (1, 0), (-1, 0))

        while heap:
            dist, i, j = heappop(heap)
            if (i, j) in visited:
                continue
            visited.add((i, j))
            #print(i, j, dist)
            if i == N -1 and j == M - 1:
                return dist
    
            for direction, (dy, dx) in enumerate(d):
                ny, nx = i + dy, j + dx

                if not (0<= ny < N and 0 <= nx < M):
                    continue

                if (ny, nx) in visited:
                    continue
                
                n_dist = dist if grid[i][j] - 1 == direction else dist + 1
                heappush(heap, (n_dist, ny, nx))