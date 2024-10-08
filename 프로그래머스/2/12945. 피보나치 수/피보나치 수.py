def solution(n):
    n1, n2, n3 = 0, 1, 1
        
    for i in range(2, n+1):
        n3 = (n1 + n2) % 1234567
        n1, n2 = n2, n3
        
    return n3