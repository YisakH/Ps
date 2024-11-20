from itertools import combinations

def solution(relations):
    answer_list = set()
    N = len(relations)
    M = len(relations[0])
    
    for r in range(1, M + 1):
        combi_list = combinations(range(M), r)
        for combi in combi_list:
            
            if any([set(a).issubset(set(combi)) for a in answer_list]):
                continue
            
            keys = set()
            for i in range(N):
            #    key = set()
            #    for c in combi:
            #        key.add(relations[i][c])
            #    if arr in keys:
            #        break
                key = tuple(relations[i][c] for c in combi)
                keys.add(key)
            
            if len(keys) == N:
                answer_list.add(tuple(combi))
                
    return len(list(answer_list))
