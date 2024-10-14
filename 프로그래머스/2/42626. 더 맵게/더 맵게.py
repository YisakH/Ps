import heapq

def solution(heap, K):
    answer = 0
    
    heapq.heapify(heap)
    
    while len(heap) > 1 and heap[0] < K:
        f1 = heapq.heappop(heap)
        f2 = heapq.heappop(heap)
        heapq.heappush(heap, f1 + f2 * 2)
        
        answer += 1
    
    return answer if heap[0] >= K else -1