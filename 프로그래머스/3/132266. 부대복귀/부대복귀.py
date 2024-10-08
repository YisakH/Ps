from collections import deque

def solution(n, roads, sources, destination):
    answer = []
    edge = [[] for _ in range(n+1)]
    result = dict()
    
    for start, end in roads:
        edge[start].append(end)
        edge[end].append(start)
    
    visit = set()
    q = deque()
    q.append([0, destination])
    visit.add(destination)
    
    while q:
        depth, node = q.popleft()
        result[node] = depth
            
        for dest in edge[node]:
            if dest not in visit:
                q.append([depth + 1, dest])
                visit.add(dest)
        
        if all(src in result for src in sources):
            break
    
    for src in sources:
        if src in result:
            answer.append(result[src])
        else:
            answer.append(-1)
        
    return answer