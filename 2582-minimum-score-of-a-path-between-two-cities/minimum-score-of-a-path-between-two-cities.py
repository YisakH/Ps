from collections import deque, defaultdict

class Solution(object):
    def minScore(self, n, roads):
        """
        :type n: int
        :type roads: List[List[int]]
        :rtype: int
        """

        edges = defaultdict(list)

        for i, j, n in roads:
            edges[i].append((j, n))
            edges[j].append((i, n))

        q = deque()
        q.append(1)
        visit = set()
        answer = float('inf')

        while q:
            cur = q.popleft()
            for dest, dist in edges[cur]:
                a, b = min(cur, dest), max(cur, dest)
                if (a, b) in visit:
                    continue
                
                visit.add((a, b))
                q.append(dest)
                answer = min(answer, dist)
            
        return answer

        


        
        