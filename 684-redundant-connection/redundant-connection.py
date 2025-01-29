class Solution:
    def findRedundantConnection(self, edges):
        # 각 노드의 부모를 자기 자신으로 초기화
        parent = list(range(len(edges) + 1))

        # 부모(루트)를 찾는 함수 (경로 압축 기법 사용)
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])  # 경로 압축
            return parent[x]

        # 두 노드를 같은 집합으로 합치는 함수
        def union(x, y):
            rootX = find(x)
            rootY = find(y)
            if rootX == rootY:
                return False  # 사이클이 발생함 (즉, 중복 간선)
            parent[rootX] = rootY  # 두 집합을 합침
            return True

        # 모든 간선을 처리하면서 사이클이 발생하는 간선을 찾기
        for u, v in edges:
            if not union(u, v):  # 만약 사이클이 생기는 간선이라면 반환
                return [u, v]
