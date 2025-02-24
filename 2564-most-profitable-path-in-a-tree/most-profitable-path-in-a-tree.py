from collections import defaultdict, deque

class Solution:
    def mostProfitablePath(self, edges: List[List[int]], bob: int, amount: List[int]) -> int:
        link = defaultdict(list)
        answer = -float('inf')
        
        for s, e in edges:
            link[s].append(e)
            link[e].append(s)
        
        bob_time = dict()
        st = [(bob, 0, [bob])]
        bob_time[bob] = 0
        bob_path = None

        while st:
            node, time, path = st.pop()
            if node == 0:
                bob_path = path
                break

            for ne in link[node]:
                if ne in bob_time:
                    continue
                st.append((ne, time + 1, path + [ne]))
                bob_time[ne] = time + 1
        
        st = [(0, 0, 0)] # node, time, cost
        alice_visit = set()
        alice_visit.add(0)
        
        while st:
            node, time, cost = st.pop()

            if node in bob_path:
                if time == bob_time[node]:
                    cost += amount[node] // 2
                elif time <= bob_time[node]:
                    cost += amount[node]
            else:
                cost += amount[node]
            
            leaf = True
            for ne in link[node]:
                if ne in alice_visit:
                    continue
                leaf = False
                alice_visit.add(ne)
                st.append((ne, time + 1, cost))

            if leaf:
                answer = max(cost, answer)
        
        return answer