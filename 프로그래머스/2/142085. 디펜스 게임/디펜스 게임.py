import heapq

def solution(n, k, enemy):
    heap = []
    
    for r, e in enumerate(enemy):
        heapq.heappush(heap, -e)
        
        while n < e and k > 0 and heap:
            cancel = -heapq.heappop(heap)
            n += cancel
            k -= 1
        
        if n < e:
            return r
        n -= e
    
    return len(enemy)