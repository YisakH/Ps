class Solution:
    def minimumCost(self, n: int, edges: List[List[int]], query: List[List[int]]) -> List[int]:
        weight = [2**20 - 1 for i in range(n)]
        parent = [i for i in range(n)]

        def find(u):
            if parent[u] == u:
                return u
            
            parent[u] = find(parent[u])
            return parent[u]
        
        def union(a, b, w):
            a_root = find(a)
            b_root = find(b)

            weight[a_root] &= weight[b_root]
            weight[a_root] &= w

            if a_root != b_root:
                parent[b_root] = a_root

        for u, v, w in edges:
            union(u, v, w)
        
        answer = []

        for u, v in query:
            u_root = find(u)
            v_root = find(v)

            if u_root == v_root:
                answer.append(weight[u_root])
            else:
                answer.append(-1)

        return answer