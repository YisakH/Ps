from collections import Counter

def solution(weights):
    answer = 0
    
    weights.sort()
    cou = Counter(weights)
    cou_keys = sorted(cou.keys())
    
    for key, val in cou.items():
        if val > 1:
            answer += val*(val-1) // 2
    
    for w in cou_keys:
        t_list = [w * i for i in [2,3,4]]
        w2_list = set()
        
        for t in t_list:
            for i in [2, 3, 4]:
                if t%i == 0 and t//i >= w:
                    w2_list.add(t//i)
                    
        w2_list.remove(w)
        
        for w2 in w2_list:
            if w2 in cou:
                answer += cou[w] * cou[w2]
    
    return answer