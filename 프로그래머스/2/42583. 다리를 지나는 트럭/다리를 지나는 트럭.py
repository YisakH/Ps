from collections import deque

def solution(bridge_length, weight, truck_weights):
    answer = 0
    q = deque([0 for _ in range(bridge_length)], maxlen = bridge_length)
    inq = 0
    total_w = 0
    
    while  q:
        out = q.popleft() if q else 0
        total_w -= out
        answer += 1
        
        if inq >= len(truck_weights):
            continue
        
        if total_w + truck_weights[inq] <= weight:
            total_w += truck_weights[inq]
            q.append(truck_weights[inq])
            inq += 1
        else:
            q.append(0)
        
    return answer