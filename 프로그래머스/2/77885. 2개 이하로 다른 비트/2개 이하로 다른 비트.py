def solution(numbers):
    answer = []
    
    for number in numbers:
        bi = bin(number)[2:]
        
        if '0' in bi:
            i = bi.rfind('0')
            new_bi = bi[:i] + '1'
            
            if i + 1 < len(bi):
                new_bi += '0'
            if i + 2 < len(bi):
                new_bi += bi[i+2:]
        
        else: # 모두 1인 경우
            new_bi = '10' if len(bi) < 2 else '10' + bi[1:]
        
        answer.append(int('0b' + new_bi, 2))
        
    return answer