class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        # node1과 node2로 시작해서 모든 노드 순회?
        dist1 = [-1 for _ in edges]
        cur = node1
        cur_dist = 0

        while dist1[cur] < 0:
            dist1[cur] = cur_dist
            cur_dist += 1
            cur = edges[cur]
            if cur < 0:
                break
        
        dist2 = [-1 for _ in edges]
        cur = node2
        cur_dist = 0

        while dist2[cur] < 0:
            dist2[cur] = cur_dist
            cur_dist += 1
            cur = edges[cur]
            if cur < 0:
                break
        
        ans_idx = -1
        ans = 9999999

        for i in range(len(edges)):
            if dist1[i] < 0 or dist2[i] < 0:
                continue
            
            if max(dist1[i], dist2[i]) < ans:
                ans_idx = i
                ans = max(dist1[i], dist2[i])
        
        return ans_idx


        
