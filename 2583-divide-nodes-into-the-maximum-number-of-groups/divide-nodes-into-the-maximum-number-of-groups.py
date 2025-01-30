from collections import deque, defaultdict

class Solution(object):
    def magnificentSets(self, n, edges):
        graph = [[] for _ in range(n + 1)]
        for s, e in edges:
            graph[s].append(e)
            graph[e].append(s)
        
        team = []
        visit = [0 for _ in range(n+1)]

        for i in range(1, n+1):
            if visit[i]:
                continue
            q = deque([i])
            subteam = set()

            while q:
                cur_node = q.popleft()
                subteam.add(cur_node)

                for dest in graph[cur_node]:
                    if visit[dest]:
                        if abs(visit[dest] - visit[cur_node]) != 1:
                            return -1
                        else:
                            continue
                    q.append(dest)
                    visit[dest] = visit[cur_node] + 1

            team.append(list(subteam))

        def bfs(start):
            """
            시작 노드로부터 가장 먼 노드까지의 거리를 계산하는 함수.
            
            :param start: 탐색을 시작할 노드의 번호 (1부터 n까지)
            :return: 시작 노드로부터 가장 먼 노드까지의 거리 (int). 
                     연결되지 않은 노드가 있을 경우 -1 반환
            """
            distance = [-1] * (n + 1)
            queue = deque()
            queue.append(start)
            distance[start] = 0  # 시작 노드의 거리는 0
            
            while queue:
                current = queue.popleft()
                for neighbor in graph[current]:
                    if distance[neighbor] == -1:
                        distance[neighbor] = distance[current] + 1
                        queue.append(neighbor)
            
            # 가장 먼 거리 찾기
            farthest = max(distance)
            if farthest == -1:
                return -1  # 모든 노드가 연결되어 있지 않음
            return farthest

        answer = 0
        for t in team:
            if len(t) <= 3:
                answer += len(t)
            else:
                max_len = 0
                for start in t:
                    max_len = max(max_len, bfs(start))
                answer += max_len + 1
            #print(answer)

        return answer