def solution(sequence, k):
    answer = [0, len(sequence) - 1]
    
    start, end = 0, 0 # start부터 end까지(end 포함)
    total = sequence[0]
    
    while start <= end < len(sequence):
        if total == k:
            if end - start + 1 < answer[1] - answer[0] + 1:
                answer = [start, end]
            
            start, end = start+1, end + 1
            if end >= len(sequence):
                break
            total -= sequence[start - 1]
            total += sequence[end] 
        
        else:
            if total < k:
                end += 1
                if end >= len(sequence):
                    break
                total += sequence[end]
            else: # k < total
                total -= sequence[start]
                start += 1
    
    return answer