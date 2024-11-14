from itertools import permutations

def getFac(n):
    answer = 1
    for i in range(2, n + 1):
        answer *= i
    return answer

def solution(n, k):
    answer = []
    usable = [i+1 for i in range(n)]
    fac = getFac(n-1)
    k -= 1
    
    for i in range(n-1, 0, -1):
        q = k // fac
        k = k % fac
        fac //= i
        answer.append(usable.pop(q))
    
    return answer + usable