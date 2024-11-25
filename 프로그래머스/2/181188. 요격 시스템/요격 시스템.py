def solution(targets):
    answer = 0
    targets.sort(key=lambda x:(x[0], x[1]))
    be = -1
    
    for [s, e] in targets:
        if be <= s: # 기존 요격 범위에서 벗어남
            be = e
            answer += 1
        else: # 기조 요격 범위에 포함
            be = min(be, e)
            
    return answer