def get_2(n):
    answer = ""
    while n:
        answer += str(n%2)
        n //= 2
    
    return answer[::-1]

def solution(s):
    cnt = 0
    zero = 0
    
    while s != "1":
        zero += s.count("0")
        val = s.count("1")
        s = get_2(val)
        cnt += 1
    
    return [cnt, zero]
        