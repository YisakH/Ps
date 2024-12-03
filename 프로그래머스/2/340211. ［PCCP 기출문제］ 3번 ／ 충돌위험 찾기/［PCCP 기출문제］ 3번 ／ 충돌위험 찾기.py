from collections import deque

def solution(points, routes):
    answer = 0
    x = len(routes)
    curidx = [points[route[0] - 1] for route in routes]
    routes = deque([deque(route) for route in routes])
    
    while True:
        sameXY = set()
        visited = set()
        for cur in curidx:
            if cur == [-1, -1]:
                continue
            cur = tuple(cur)
            if cur in sameXY and cur not in visited:
                visited.add(cur)
                answer += 1
            sameXY.add(cur)
        
        for idx, path in enumerate(routes):
            if not path:
                curidx[idx] = [-1, -1]
                continue
                
            [curY, curX] = curidx[idx]
            [targetY, targetX] = points[path[0] - 1]
            
            if curY == targetY and curX == targetX:
                routes[idx].popleft()
                if routes[idx]:
                    targetY, targetX = points[path[0] - 1]
                else:
                    curidx[idx] = [-1,-1]
                    continue
            
            if targetY != curY:
                curY += (targetY-curY)//abs(targetY-curY)
            elif targetX != curX:
                curX += (targetX-curX)//abs(targetX-curX)
            else:
                routes[idx].popleft()
                
            curidx[idx] = [curY, curX]
            
        if not sum([len(arr) for arr in routes]):
            break
    
    return answer