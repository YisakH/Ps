def solution(n):
    def dfs(y):
        nonlocal answer
        
        if y == n:
            answer += 1
            return
        
        for x in range(n):
            if x in arr or y + x in diagonal1 or y - x in diagonal2:
                continue
            
            arr.add(x)
            diagonal1.add(y+x)
            diagonal2.add(y-x)
            
            dfs(y+1)
            
            arr.remove(x)
            diagonal1.remove(y+x)
            diagonal2.remove(y-x)
            
    answer = 0
    arr = set()
    diagonal1 = set()
    diagonal2 = set()
    
    dfs(0)

    return answer