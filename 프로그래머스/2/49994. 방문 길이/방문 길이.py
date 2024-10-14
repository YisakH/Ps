def solution(dirs):
    answer = 0
    visit = set() # ((sy, sx), (ey, ex))
    
    cy, cx = 0, 0
    directions = {"U": (1, 0), "R": (0, 1), "L": (0, -1), "D":(-1, 0)}
    
    for route in dirs:
        dy, dx = directions[route]
        ny, nx = cy + dy, cx + dx
        
        if not (-5 <= ny <= 5 and -5 <= nx <= 5):
            continue
        route = ((cy, cx), (ny, nx))
        r_route = ((ny, nx), (cy, cx))
        
        if route not in visit and r_route not in visit:
            visit.add(route)
            visit.add(r_route)
            answer += 1
            
        cy, cx = ny, nx
    
    return answer