from heapq import heappush, heappop

class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        events.sort(key=lambda x:(x[0], x[1]))
        ans = 0
        heap = []
        idx = 0

        end_day = max([e for _, e in events])
        
        for day in range(events[0][0], end_day + 1):
            while idx < len(events) and events[idx][0] <= day <= events[idx][1]:
                heappush(heap, [events[idx][1], events[idx][0]])
                idx += 1
            
            while heap and not (heap[0][1] <= day <= heap[0][0]):
                heappop(heap)
            
            if heap:
                heappop(heap)
                ans += 1
        return ans