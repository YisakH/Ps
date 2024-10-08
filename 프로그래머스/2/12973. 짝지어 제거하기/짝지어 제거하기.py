def solution(s):
    
    stack = []
    
    for c in s:
        if not stack:
            stack.append(c)
        elif stack[-1] == c:
            stack.pop()
        else:
            stack.append(c)
    
    if stack:
        return 0
    else:
        return 1
        
            
            