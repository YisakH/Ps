def solution(s):    
    cnt = 0
    
    for c in s:
        if c == '(':
            cnt += 1
        else:
            cnt -= 1
            
        if cnt < 0:
            return False
    
    if cnt == 0:
        return True
    
    return False