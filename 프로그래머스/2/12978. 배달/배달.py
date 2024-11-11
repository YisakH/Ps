def solution(N, roads, K):
    answer = 0
    w = [[float('inf') for _ in range(N)] for _ in range(N)]
    
    for a, b, c in roads:
        if w[a-1][b-1] > c:
            w[a-1][b-1] = c
            w[b-1][a-1] = c
            
    cur = 0
    dist = [float('inf') for _ in range(N)]
    dist[0] = 0
    not_visit = set([i for i in range(N)])
    
    for _ in range(N - 1):
        not_visit.remove(cur)
        
        for i in list(not_visit):
            if dist[cur] + w[cur][i] < dist[i]:
                dist[i] = dist[cur] + w[cur][i]
        
        min_next = list(not_visit)[0]
        
        for ne in list(not_visit):
            if dist[min_next] > dist[ne]:
                min_next = ne
            
        cur = min_next
    
    return len([True for d in dist if d <= K])