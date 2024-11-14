from collections import deque

def bfs(N, M, y, x, maps, visit):
    d = ((-1, 0), (1, 0), (0, 1), (0, -1))
    q = deque()
    q.append((y, x))
    visit.add((y, x))
    answer = int(maps[y][x])
    
    while (q):
        y, x = q.popleft()
    
        for dy, dx in d:
            ny, nx = y + dy, x + dx

            if not (0 <= ny < N and 0 <= nx < M):
                continue
            if (ny, nx) in visit or maps[ny][nx] == 'X':
                continue

            q.append((ny, nx))
            visit.add((ny, nx))
            answer += int(maps[ny][nx])
    
    return answer

def solution(maps):
    answer = []
    N = len(maps)
    M = len(maps[0])
    visit = set()
    
    for i in range(N):
        for j in range(M):
            if maps[i][j] != 'X' and (i, j) not in visit:
                answer.append(bfs(N, M, i, j, maps, visit))
    answer.sort()
    answer = answer if len(answer) > 0 else [-1]
    return answer