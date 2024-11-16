from collections import deque

def bfs(y, x, place):
    q = deque()
    q.append((y, x, 0))
    d = ((-1, 0), (1, 0), (0, -1), (0, 1))
    visit = {(y, x)}
    
    while q:
        cy, cx, distance = q.popleft()
        if distance == 2:
            continue
        
        for dy, dx in d:
            ny, nx = cy + dy, cx + dx
            if not (0<=ny<5 and 0<=nx<5):
                continue
            if (ny, nx) in visit:
                continue
            if place[ny][nx] == 'X':
                continue
            if place[ny][nx] == 'P':
                return True
            visit.add((ny, nx))
            q.append((ny, nx, distance + 1))
    return False
            
        

def solution(places):
    answer = []
    for place in places:
        check = False
        for i in range(5):
            if check:
                break
            for j in range(5):
                if place[i][j] == 'P' and bfs(i, j, place):
                    check = True
                    break
                    
        if check:
            answer.append(0)
        else:
            answer.append(1)
                     
    return answer