from collections import deque

class Solution(object):
    def findMaxFish(self, grid):
        visit = set()
        d = ((-1, 0), (1, 0), (0, 1), (0, -1))
        answer = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 0 or (i, j) in visit:
                    continue
                
                q = deque()
                q.append((i, j))
                visit.add((i, j))
                total_fish = 0

                while q:
                    y, x = q.popleft()
                    total_fish += grid[y][x]

                    for dy, dx in d:
                        ny, nx = y + dy, x + dx
                        if not (0 <= ny < len(grid) and 0 <= nx < len(grid[0])):
                            continue
                        if (ny, nx) in visit or grid[ny][nx] == 0:
                            continue
                        visit.add((ny, nx))
                        q.append((ny, nx))

                answer = max(answer, total_fish)
        return answer