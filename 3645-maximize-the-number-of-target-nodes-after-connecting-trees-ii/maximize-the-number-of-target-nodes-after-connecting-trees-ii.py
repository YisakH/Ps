from collections import defaultdict

class Solution:
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]]) -> List[int]:
        tree1 = defaultdict(list)
        tree2 = defaultdict(list)

        for u, v in edges1:
            tree1[u].append(v)
            tree1[v].append(u)

        for u, v in edges2:
            tree2[u].append(v)
            tree2[v].append(u)

        def dfs(tree, N, cnt):
            even, odd = 0, 0
            st = [[0, -1, 0]]
            check = None
            if cnt:
                check = [False for _ in range(N + 1)]

            while st:
                cur, before, depth = st.pop()
                if depth % 2 == 0:
                    even += 1
                    if cnt:
                        check[cur] = True
                elif depth % 2 == 1:
                    odd += 1
                
                for ne in tree[cur]:
                    if ne == before:
                        continue
                    st.append([ne, cur, depth + 1])
                
            return even, odd, check
        
        e1, o1, check = dfs(tree1, len(edges1), True)
        e2, o2, _ = dfs(tree2, len(edges2), False)
        e2 = max(e2, o2)
        ans = []

        for i in range(len(edges1) + 1):
            if check[i]: #짝수
                ans.append(e1 + e2)
            else:
                ans.append(o1 + e2)

        return ans
