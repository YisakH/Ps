def solution(cap, n, deliveries, pickups):
    answer = 0
    
    for i in range(n-2, -1, -1):
        deliveries[i] += deliveries[i+1]
        pickups[i] += pickups[i+1]
    
    deidx, piidx = n-1, n-1
    while deidx >= 0 and deliveries[deidx] == 0:
        deidx -= 1
    while piidx >= 0 and pickups[piidx] == 0:
        piidx -= 1
        
    total_delivered = 0
    total_pickuped = 0
    
    while deidx >= 0 or piidx >= 0:
        answer += max(deidx + 1, piidx + 1) * 2
        total_delivered += cap
        total_pickuped += cap
        
        while deidx >= 0 and deliveries[deidx] <= total_delivered:
            deidx -= 1
        while piidx >= 0 and pickups[piidx] <= total_pickuped:
            piidx -= 1       
        
    return answer