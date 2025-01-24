class Solution(object):
    def eventualSafeNodes(self, graph):
        in_graph = [[] for _ in graph]
        
        for i, out_nodes in enumerate(graph):
            for node in out_nodes:
                in_graph[node].append(i)
            graph[i] = set(out_nodes)
        
        q = deque()

        for i, edge in enumerate(graph):
            if len(edge) == 0:
                q.append(i)

        answer = []
        while q:
            node = q.popleft()
            if len(graph[node]) == 0:
                answer.append(node)
                for fr in in_graph[node]:
                    graph[fr].remove(node)
                    if len(graph[fr]) == 0:
                        q.append(fr)
            else:
                break
        
        return sorted(answer)