# dp = [1, ]
def solution(s):
    result = 1001
    if len(s) == 1:
        return 1
    
    for l in range(1, len(s)//2 + 1):        
        key = ""
        key_index = -1
        cnt = dict()
        
        for start in range(0, len(s)-l+1, l):
            cur = s[start:start+l]
            if cur == key:
                if key_index not in cnt:
                    cnt[key_index] = 2
                else:
                    cnt[key_index] += 1
            else:
                key = cur
                key_index = start
        
        answer = ""
        start = 0
        while start < len(s):
            if start in cnt:
                answer += str(cnt[start]) + s[start: start + l]
                start += cnt[start] * l
            else:
                answer += s[start: start + l]
                start += l
        
        result = result if result < len(answer) else len(answer)
        
    return result