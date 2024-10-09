def solution(want, number, discount):
    answer = 0
    
    cnt_dict = dict()
    for thing, cnt in zip(want, number):
        cnt_dict[thing] = cnt
    
    for start in range(0, len(discount) - 10 + 1):
        end = start + 10
        can_buy = dict()
        
        for i in range(start, end):
            if discount[i] not in can_buy:
                can_buy[discount[i]] = 1
            else:
                can_buy[discount[i]] += 1
        
        if can_buy == cnt_dict:
            answer += 1
        
    return answer