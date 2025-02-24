from collections import defaultdict
from math import inf
from typing import List

class Solution:
    def mostProfitablePath(self, edges: List[List[int]], bob: int, amount: List[int]) -> int:
        n = len(amount)
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        # 각 노드에 대해 Bob이 도착하는 시간을 저장 (경로에 없으면 inf)
        bobTime = [inf] * n
        
        # Bob이 0으로 가는 경로 상에 있는 노드에 대해 도착 시간을 계산하는 DFS
        def dfsBob(u: int, parent: int, t: int) -> bool:
            if u == 0:  # 0에 도착하면
                bobTime[u] = t
                return True
            found = False
            for v in graph[u]:
                if v == parent:
                    continue
                if dfsBob(v, u, t + 1):
                    found = True
            if found:
                bobTime[u] = t
            return found
        
        dfsBob(bob, -1, 0)
        
        ans = -inf
        
        # Alice가 0에서 출발해 리프로 가는 동안의 net profit 계산 DFS
        def dfsAlice(u: int, parent: int, t: int, total: int) -> None:
            nonlocal ans
            # 도착 시간 t와 bobTime[u]를 비교하여 비용/보상 반영
            if t < bobTime[u]:
                total += amount[u]
            elif t == bobTime[u]:
                total += amount[u] // 2
            # Bob이 먼저 도착했다면(total 변화 없음)
            
            # 리프 노드에 도착했다면 최대값 갱신
            if u != 0 and len(graph[u]) == 1:
                ans = max(ans, total)
            
            for v in graph[u]:
                if v == parent:
                    continue
                dfsAlice(v, u, t + 1, total)
        
        dfsAlice(0, -1, 0, 0)
        return ans