def solution(clothes):
    answer = 1
    dic = dict()
    for cloth, category in clothes:
        if category not in dic:
            dic[category] = 1
        else:
            dic[category] += 1
    
    for val in dic.values():
        answer *= val + 1
    
    return answer - 1