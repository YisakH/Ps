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
        visit = set([1])
        answer = float('inf')

        while q:
            cur = q.popleft()
            for dest, dist in edges[cur]:
                answer = min(answer, dist)

                if dest in visit:
                    continue
                
                visit.add(dest)
                q.append(dest)
            
        return answer

        


        
        