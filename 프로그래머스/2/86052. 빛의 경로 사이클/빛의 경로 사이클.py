def solution(grid):
    answer = []
    directions = ((0, -1), (-1, 0), (0, 1), (1, 0))
    
    def move(y, x, d):
        nonlocal N, M
        dy, dx = directions[d]
        return (y + dy) % N, (x + dx) % M,d
    
    def rotate(y, x, d):
        if grid[y][x] == 'R':
            return (d+1) % 4
        elif grid[y][x] == 'L':
            return (d-1) % 4
        return d
        
    N, M = len(grid), len(grid[0])
    visited = [[[False for _ in range(4)] for _ in range(M)] for _ in range(N)]
    
    for y in range(N):
        for x in range(M):
            for d in range(4):
                length = 0
                while visited[y][x][d] == False:
                    length += 1
                    visited[y][x][d] = True
                    d = rotate(y, x, d)
                    y, x, d = move(y, x, d)
                if length > 0:
                    answer.append(length)
    
    return sorted(answer)