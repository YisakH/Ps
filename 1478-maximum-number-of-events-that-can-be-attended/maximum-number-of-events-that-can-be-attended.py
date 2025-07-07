from heapq import heappush, heappop

class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        events.sort()
        ans = 0
        heap = []
        idx = 0

        end_day = max([e[1] for e in events])
        
        for day in range(events[0][0], end_day + 1):
            while idx < len(events) and events[idx][0] <= day:
                heappush(heap, events[idx][1])
                idx += 1
            
            while heap and day > heap[0]:
                heappop(heap)
            
            if heap:
                heappop(heap)
                ans += 1
        return ans