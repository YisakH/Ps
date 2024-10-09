def solution(progresses, speeds):
    complete = [(100-pro + speed - 1) // speed for pro, speed in zip(progresses, speeds)]
    answer = []
    i = 0
    
    while i < len(complete):
        j = i
        
        while j < len(complete) and complete[j] <= complete[i]:
            j += 1
        
        answer.append(j - i)
        i = j
        
    return answer