from collections import deque

def solution(land):
    answer = 0
    visit = set()
    
    def bfs(y, x):
        q = deque()
        d = ((1, 0), (0, 1), (0, -1), (-1, 0))
        q.append((y, x))
        visit.add((y, x))
        visit_list = []
        
        while q:
            (y, x) = q.pop()
            visit_list.append((y, x))
            
            for dy, dx in d:
                ny, nx = y + dy, x + dx
                
                if not (0 <= ny < len(land) and 0 <= nx < len(land[0])):
                    continue
                if land[ny][nx] == 0:
                    continue
                
                if (ny, nx) not in visit:
                    visit.add((ny, nx))
                    q.append((ny, nx))
        
        return visit_list
            
    oil = [0 for _ in range(len(land[0]))]
    
    for i in range(len(land)):
        for j in range(len(land[0])):
            if land[i][j] == 1 and (i, j) not in visit:
                visit_list = bfs(i, j)
                x_set = set([x for _, x in visit_list])
                
                for x in x_set:
                    oil[x] += len(visit_list)
                
    return max(oil)