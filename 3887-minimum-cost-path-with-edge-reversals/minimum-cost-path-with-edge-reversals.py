from heapq import heappush, heappop

class Solution:
    def minCost(self, n: int, edgeArr: List[List[int]]) -> int:
        # 사이클 존재함
        # 방문했는지 관리해야 함
        visit = [False for _ in range(n)]
        edges = [[] for _ in range(n)]

        for u, v, w in edgeArr:
            edges[u].append([w, v])
            edges[v].append([2 * w, u])
        
        q = [[0, 0]]

        while q:
            curw, cur = heappop(q)
            
            if visit[cur]:
                continue

            visit[cur] = True

            if cur == n - 1:
                return curw
            
            for destw, dest in edges[cur]:
                if visit[dest]:
                    continue
                
                heappush(q, [curw + destw, dest])

        return -1