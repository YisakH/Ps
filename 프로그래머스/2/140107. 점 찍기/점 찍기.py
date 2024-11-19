from math import sqrt

def solution(k, d):
    y = d - (d % k)
    answer = 0
    
    
    for x in range(0, d + 1, k):
        while sqrt(y**2 + x ** 2) > d:
            y -= k
        answer += (y // k + 1)
    
    return answer