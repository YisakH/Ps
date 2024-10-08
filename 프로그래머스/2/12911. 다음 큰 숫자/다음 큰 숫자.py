def solution(n):    
    for i in range(n+1, 2000001):
        if bin(n).count('1') == bin(i).count('1'):
            return i