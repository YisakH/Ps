def getIdx(string):
    return [ord(ch) - ord('a') + 1 for ch in string]

def getN(ban):
    ban_idx = getIdx(ban)
    answer = 0
    N = len(ban_idx)
    
    for i in range(N):
        answer += ban_idx[i] * (26 ** (N - i -1))
        
    return answer

def convert_to_string(n):
    # n는 전체 주문서에서의 순위(1-indexed)
    L = 1
    offset = 0
    while offset + 26 ** L < n:
        offset += 26 ** L
        L += 1
    # n_adjusted는 현재 길이 L에 해당하는 주문 내의 위치 (1-indexed)
    n_adjusted = n - offset
    result = ""
    # n_adjusted - 1을 0부터 시작하는 숫자로 변환한 뒤 L자리 26진법 수로 변환
    n_adjusted -= 1
    for i in range(L):
        power = 26 ** (L - i - 1)
        digit = n_adjusted // power
        result += chr(97 + digit)
        n_adjusted %= power
    return result

def solution(n, bans):
    bans.sort(key=lambda x:getN(x))
    for ban in bans:
        if getN(ban) <= n:
            n += 1
    answer = ''
    length = 1
    offset = 0
    
    while offset + 26 ** length < n:
        offset += 26 ** length
        length += 1
    
    return convert_to_string(n)