from heapq import heappush, heappop

N, M, X = map(int, input().split())

arr = [[float('inf') for _ in range(N)] for _ in range(N)]

for _ in range(M):
    s, e, w = map(int, input().split())
    arr[s-1][e-1] = w

for i in range(N):
    arr[i][i] = 0

heap = [[0, X-1]]
visit = set()
distance1 = [0 for _ in range(N)]

while heap:
    dist, node = heappop(heap)
    if node in visit:
        continue
    distance1[node] = dist
    
    visit.add(node)
    
    for i in range(N):
        if arr[i][node] < float('inf') and i not in visit:
            heappush(heap, [dist + arr[i][node], i])

heap = [[0, X-1]]
visit = set()
distance2 = [0 for _ in range(N)]

while heap:
    dist, node = heappop(heap)
    if node in visit:
        continue
    distance2[node] = dist
    
    visit.add(node)
    
    for i in range(N):
        if arr[node][i] < float('inf') and i not in visit:
            heappush(heap, [dist + arr[node][i], i])

print(max([i + j for i, j in zip(distance1, distance2)]))