from math import floor, ceil, sqrt

def solution(r1, r2):
    answer = 0
    
    r1_y, r2_y = r1, r2
    
    for x in range(r2 + 1):
        r1_y = ceil(sqrt(max(r1**2-x**2, 0)))
        r2_y = floor(sqrt(r2**2 -x**2))
        
        answer += r2_y - r1_y + 1
    
    answer = (answer - (r2 - r1 + 1)) * 4
        
    return answer