from collections import defaultdict

class Solution(object):
    def queryResults(self, limit, queries):
        q = defaultdict(int)
        color = defaultdict(int)
        total_cnt = 0
        answer = []

        for i, c in queries:
            if q[i] != c:
                color[q[i]] -= 1
                if color[q[i]] == 0:
                    total_cnt -= 1
            
                q[i] = c
                color[c] += 1
                if color[c] == 1:
                    total_cnt += 1
            answer.append(total_cnt)
        
        return answer



        