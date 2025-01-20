from heapq import heappush, heappop

class Solution(object):
    def minCost(self, grid):
        N = len(grid)
        M = len(grid[0])
        
        heap = []
        heappush(heap, (0, 0, 0))  # (비용, 행, 열)
        d = ((0, 1), (0, -1), (1, 0), (-1, 0))  # 방향 벡터
        min_cost = [[float('inf')] * M for _ in range(N)]
        min_cost[0][0] = 0

        while heap:
            dist, i, j = heappop(heap)

            # 현재 위치에 최소 비용으로 도달한 경우가 아닌 경우 스킵
            if dist > min_cost[i][j]:
                continue

            # 목표에 도달한 경우 비용 반환
            if i == N - 1 and j == M - 1:
                return dist

            # 네 방향 탐색
            for direction, (dy, dx) in enumerate(d):
                ny, nx = i + dy, j + dx

                if 0 <= ny < N and 0 <= nx < M:
                    # 방향에 따라 비용 계산
                    n_dist = dist if grid[i][j] - 1 == direction else dist + 1
                    if n_dist < min_cost[ny][nx]:
                        min_cost[ny][nx] = n_dist
                        heappush(heap, (n_dist, ny, nx))