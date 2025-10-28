from collections import deque

def accessable(i, j, arr):
    n, m = len(arr), len(arr[0])
    if i == 0 or j == 0 or i == n -1 or j == m - 1:
        return True
    
    if i - 1 >= 0 and arr[i-1][j] == 0:
        return True
    if i + 1 < n and arr[i + 1][j] == 0:
        return True
    if j - 1 >= 0 and arr[i][j-1] == 0:
        return True
    if j + 1 < m and arr[i][j+1] == 0:
        return True
    return False

def setOut(grid):
    visit = set()
    n, m = len(grid), len(grid[0])
    q = deque()
    
    
    for i in range(n):
        for j in range(m):
            if (i == 0 or j == 0 or i == n - 1 or j == m - 1) and grid[i][j] == '.':
                grid[i][j] = 0
                
            elif grid[i][j] != 0:
                continue
            elif (i, j) in visit:
                continue
            
            q.append((i, j))
            d = ((-1, 0), (1, 0), (0, -1), (0, 1))
            while q:
                y, x = q.popleft()
                grid[y][x] = 0
                
                for dy, dx in d:
                    ny, nx = y + dy, x + dx
                    if not (0 <= ny < n and 0 <= nx < m):
                        continue
                    if (ny, nx) in visit:
                        continue
                    if grid[ny][nx] != 0 and grid[ny][nx] != '.':
                        continue
                        
                    visit.add((ny, nx))
                    q.append((ny, nx))         
            

def getAll(ch, grid):
    n, m = len(grid), len(grid[0])
    for i in range(n):
        for j in range(m):
            if grid[i][j] == ch:
                grid[i][j] = '.'

def getOne(ch, grid):
    n, m = len(grid), len(grid[0])
    for i in range(n):
        for j in range(m):
            if grid[i][j] == ch and accessable(i, j, grid):
                grid[i][j] = '.'
    

def solution(storage, requests):
    answer = 0
    n, m = len(storage), len(storage[0])
    storage = [[ch for ch in storage[i]] for i in range(len(storage))]
    for r in requests:
        if len(r) > 1:
            getAll(r[0], storage)
        else:
            getOne(r, storage)
        setOut(storage)
    
    for i in range(n):
        for j in range(m):
            if storage[i][j] != 0 and storage[i][j] != '.':
                answer += 1

        
    return answer