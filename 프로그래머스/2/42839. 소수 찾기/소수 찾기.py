import math

def dfs(s, number, sosu, use, visit):
    answer = 0   
    
    for i, num in enumerate(number):
        
        if use[i]:
            continue
            
        s += str(num)
        
        if s in visit:
            s = s[:-1]
            continue
        
        if sosu[int("".join(s))]:
            sosu[int("".join(s))] = False
            answer += 1 
        
        use[i] = True
        visit.add(s)
        
        answer += dfs(s, number, sosu, use, visit)
        use[i] = False
        visit.remove(s)
        s = s[:-1]
    
    return answer

def solution(numbers):
    answer = 0
    
    sosu = [True for _ in range(10 ** len(numbers))]
    sosu[0], sosu[1] = False, False
    
    for i in range(2, int(math.sqrt(len(sosu))) + 1):
        if not sosu[i]:
            continue
        for j in range(2, len(sosu) // i):
            sosu[i*j] = False        
    
        
    return dfs('', numbers, sosu, [False for _ in range(len(numbers))], set())