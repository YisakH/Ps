from math import gcd

def solution(arr):
    answer = arr[-1]
    
    for i in range(len(arr) - 1):
        g = gcd(arr[i], answer)
        answer = g * (answer // g) * (arr[i] // g)
        
    return answer