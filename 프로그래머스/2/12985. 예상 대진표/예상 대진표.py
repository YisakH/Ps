def solution(n,a,b):
    answer = 1
    
    a = (a+1)//2
    b = (b+1)//2
    
    while a != b:
        a = (a+1)//2
        b = (b+1)//2
        answer += 1

    return answer