from collections import defaultdict

class Solution:
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]], k: int) -> List[int]:
        
        tree1 = defaultdict(list)
        tree2 = defaultdict(list)

        for u, v in edges1:
            tree1[u].append(v)
            tree1[v].append(u)
        for u, v in edges2:
            tree2[u].append(v)
            tree2[v].append(u)
        
        N, M = len(tree1), len(tree2)
        
        def dfs(tree, distance, before, cur, k):
            if k < 0:
                return 0

            res = 1
            if distance == k:
                return res

            for v in tree[cur]:
                if v == before:
                    continue
                
                res += dfs(tree, distance + 1, cur, v, k)
            
            return res
        
        tree2_max = max([dfs(tree2, 0, -1, i, k-1) for i in range(M)]) 
        answer = []

        for i in range(N):
            answer.append(dfs(tree1, 0, -1, i, k) + tree2_max)

        return answer