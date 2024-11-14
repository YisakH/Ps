def func(p):
    if p == "":
        return ""
    
    st = 1 if p[0] == '(' else -1
    index = 1
    
    while st:
        if p[index] == '(':
            st += 1
        else:
            st -= 1
        index += 1
    
    u = p[:index]
    v = p[index:] if index < len(p) else ""
    
    if u[0] == '(': # 올바른 괄호 문자열
        return u + func(v)
    
    answer = '(' + func(v) + ')'
    for ch in u[1:-1]:
        answer += '(' if ch == ')' else ')'
    
    return answer
    

def solution(p):   
    
    return func(p)