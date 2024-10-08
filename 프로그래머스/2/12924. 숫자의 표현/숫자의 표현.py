def solution(n):
    summ = [i for i in range(n+1)]
    answer = 0
    
    for i in range(1, n+1):
        summ[i] += summ[i-1]
    
    for j in range(n+1):
        start = 0
        end = j
        
        while start <= end:
            mid = (end + start) // 2
            if summ[j] - summ[mid] == n:
                answer += 1
                break
            
            if summ[j] - summ[mid] > n:
                start = mid + 1
            else:
                end = mid - 1    
    
    return answer