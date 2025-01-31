from collections import deque

class Solution(object):
    def largestIsland(self, grid):
        N = len(grid)
        M = len(grid[0])
        directions = [(-1,0), (1,0), (0,-1), (0,1)]
        island_id = 2  # 섬 ID는 2부터 시작 (0과 1과 구분하기 위함)
        island_size = {}  # 각 섬 ID에 대한 크기 저장
        id_grid = [[0]*M for _ in range(N)]  # 각 셀의 섬 ID 매핑

        # 모든 섬을 탐색하고 ID 부여
        for i in range(N):
            for j in range(M):
                if grid[i][j] == 1 and id_grid[i][j] == 0:
                    q = deque()
                    q.append((i, j))
                    id_grid[i][j] = island_id
                    size = 1
                    while q:
                        y, x = q.popleft()
                        for dy, dx in directions:
                            ny, nx = y + dy, x + dx
                            if 0 <= ny < N and 0 <= nx < M and grid[ny][nx] == 1 and id_grid[ny][nx] == 0:
                                q.append((ny, nx))
                                id_grid[ny][nx] = island_id
                                size += 1
                    island_size[island_id] = size
                    island_id += 1

        # 모든 셀이 1인 경우, 전체 크기가 최대
        if not island_size:
            return 1

        answer = max(island_size.values())

        # 모든 0 셀을 확인하며 최대 섬의 크기 계산
        for i in range(N):
            for j in range(M):
                if grid[i][j] == 0:
                    neighbor_ids = set()
                    for dy, dx in directions:
                        ni, nj = i + dy, j + dx
                        if 0 <= ni < N and 0 <= nj < M and id_grid[ni][nj] > 1:
                            neighbor_ids.add(id_grid[ni][nj])
                    total = 1  # 현재 셀을 1로 바꾸는 것
                    for nid in neighbor_ids:
                        total += island_size[nid]
                    answer = max(answer, total)

        return answer