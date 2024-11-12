from collections import deque

def bfs(maps, start, target):
    q = deque() # i, j, time, 레버
    visit = set()
    N = len(maps)
    M = len(maps[0])
    
    for i, line in enumerate(maps):
        j = line.find(start)
        if j != -1:
            q.append((i, j, 0))
            visit.add((i, j))
    
    d = ((1, 0), (-1, 0), (0, 1), (0, -1))
    
    while q:
        y, x, time = q.popleft()
        
        for dy, dx in d:
            ny, nx = y + dy, x + dx
            
            if not (0 <= ny < N and 0 <= nx < M):
                continue
            
            if maps[ny][nx] == 'X':
                continue
            
            elif maps[ny][nx] == target:
                return time + 1
            
            if (ny, nx) in visit:
                continue
            
            q.append((ny, nx, time + 1))
            visit.add((ny, nx))
    
    return -1

def solution(maps):
    answer = 0
    
    lever_time = bfs(maps, 'S', 'L')
    if lever_time < 0:
        return -1
    
    end_time = bfs(maps, 'L', 'E')
    if end_time < 0:
        return -1
            
    return lever_time + end_time