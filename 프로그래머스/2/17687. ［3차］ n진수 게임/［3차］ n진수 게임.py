def getN(num, n):
    # num을 n진법으로
    result = ""
    dic = {i:str(i) for i in range(10)}
    dic.update({10:'A', 11:'B', 12:'C', 13:'D', 14:'E', 15:'F'})
    while num:
        result += dic[num%n]
        num //= n
    
    return result[::-1]

def solution(n, t, m, p):
    st = "0"
    answer = ""
    for i in range(m*t):
        st += getN(i, n)
    
    for i in range(t):
        answer += st[p - 1 + m * i]
        
    return answer
    