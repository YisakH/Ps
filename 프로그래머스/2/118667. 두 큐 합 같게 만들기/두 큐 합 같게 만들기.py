from collections import deque

def solution(queue1, queue2):
    answer = 0
    
    q = queue1 + queue2
    start = 0
    end = len(queue1) - 1
    
    if sum(q) % 2 != 0:
        return -1
    
    target = sum(q) // 2
    cur = sum(q[start:end + 1])
    
    while target != cur:
        if target < cur:
            start += 1
        
            if start > end:
                break
                
            cur -= q[start - 1]
        else:
            end += 1
            if end >= len(q) - 1:
                break
    
            cur += q[end]
        
        answer += 1
        
    return answer if target == cur else -1