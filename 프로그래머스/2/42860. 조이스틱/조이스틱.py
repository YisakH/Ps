import string
from collections import deque

def solution(name):
    alpha_dict = {key:val for val, key in enumerate(string.ascii_uppercase)}
    answer = sum([min(26 - alpha_dict[ch], alpha_dict[ch]) for ch in name])
    visit = [n == 'A' for n in name] # [False, False, False, ..., False]
    
    score = dict()
    q = deque()
    visit[0] = True
    q.append([visit.copy(), 0, 0])
    
    while q:
        v, i, d = q.popleft()
        cur_score = v.count(True)
        
        if cur_score == len(name):
            return answer + d
        
        if cur_score in score and score[cur_score] + len(name) < d :
            continue
        
        r = i + 1 if i + 1 < len(name) else 0
        l = i - 1 if i - 1 >= 0 else len(name) - 1
        
        if v[r] == False:
            v[r] = True
            score[cur_score + 1] = d + 1
            q.append([v.copy(), r, d + 1])
            v[r] = False
        else:
            q.append([v.copy(), r, d + 1])
            

        if v[l] == False:
            v[l] = True
            score[cur_score + 1] = d + 1
            q.append([v.copy(), l, d + 1])
            v[l] = False
        else:
            q.append([v.copy(), l, d + 1])
            
    return -1