from math import sqrt

def solution(begin, end):
    answer = [1 for _ in range(end - begin + 1)]
    
    for i in range(len(answer)):
        num = begin + i
        for j in range(2, int(sqrt(num) + 1) + 1):
            if num % j == 0:
                if num // j <= 10_000_000:
                    answer[i] = num // j
                    break
                else:
                    answer[i] = j
                
    if begin == 1:
        answer[0] = 0
    
    return answer