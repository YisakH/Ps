def dfs(visit, k, dungeons, depth):
    max_depth = depth

    for i, (minimum, need) in enumerate(dungeons):
        if i not in visit and k >= minimum:
            visit.append(i)
            k -= need
            max_depth = max(max_depth, dfs(visit, k, dungeons, depth + 1))
            k += need
            visit.pop()
    return max_depth

def solution(k, dungeons):
    
    return dfs([], k, dungeons, 0)
    
    
        
        
    return answer