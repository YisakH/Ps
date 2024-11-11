from collections import Counter
from itertools import combinations

def solution(orders, course):
    answer = []
    
    for c in course:
        counter = Counter()
        for order in orders:
            order = sorted(order)
            counter.update((combinations(order, c)))
        
        if counter:
            max_val = max(counter.values())
            if max_val < 2:
                continue
            c_result = sorted(["".join(key) for key, val in counter.items() if val == max_val])

            answer.extend(c_result)
    
    answer.sort()
    
    return answer