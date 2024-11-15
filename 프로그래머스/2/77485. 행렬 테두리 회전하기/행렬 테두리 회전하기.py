def solution(rows, columns, queries):
    answer = []    
    arr = [[columns*i + j for j in range(1, columns + 1)] for i in range(rows)]
    
    for y1, x1, y2, x2 in queries:
        x1, y1, x2, y2 = x1 - 1, y1 - 1, x2 -1, y2 -1
        
        cury, curx = y1, x1
        before_val = arr[y1][x1]
        min_val = before_val
        
        for curx in range(x1 + 1, x2 + 1):
            after = arr[cury][curx]
            arr[cury][curx] = before_val
            before_val = after
            min_val = min(before_val, min_val)
            
        for cury in range(y1 + 1, y2 + 1):
            after = arr[cury][curx]
            arr[cury][curx] = before_val
            before_val = after
            min_val = min(before_val, min_val)
            
        for curx in reversed(range(x1 , x2)):
            after = arr[cury][curx]
            arr[cury][curx] = before_val
            before_val = after
            min_val = min(before_val, min_val)
            
        for cury in reversed(range(y1, y2 )):
            after = arr[cury][curx]
            arr[cury][curx] = before_val
            before_val = after
            min_val = min(before_val, min_val)
            
        answer.append(min_val)
    
    return answer