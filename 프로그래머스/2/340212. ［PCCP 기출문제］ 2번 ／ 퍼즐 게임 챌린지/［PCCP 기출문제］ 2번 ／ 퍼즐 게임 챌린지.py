def checkClear(diffs, times, limit, level):
    find = True
    total_time = times[0]
        
    for i in range(1, len(diffs)):
        if diffs[i] > level:
            total_time += (diffs[i]-level) * (times[i] + times[i-1]) + times[i]
        else:
            total_time += times[i]
        if total_time > limit:
            find = False
            break
    
    return find

def solution(diffs, times, limit):
    answer = diffs[0]
    r = max(diffs)
    l = 1
    
    while l <= r:
        level = (l+r)//2 # level은 해결 가능, level - 1은 해결 불가능
        
        if checkClear(diffs, times, limit, level):
            if not checkClear(diffs, times, limit, level - 1):
                return level
            else:
                r = level - 1
        else:
            l = level + 1
    
    return answer