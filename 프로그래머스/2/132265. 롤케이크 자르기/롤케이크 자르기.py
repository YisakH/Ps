from collections import Counter

def solution(topping):
    answer = 0
    remain = Counter(topping)
    left_set = set()
    right_set = set(remain)
    
    for to in topping:
        if to not in left_set:
            left_set.add(to)
            
        remain[to] -= 1
        if remain[to] == 0:
            right_set.remove(to)
        
        if len(left_set) == len(right_set):
            answer += 1
    
    return answer