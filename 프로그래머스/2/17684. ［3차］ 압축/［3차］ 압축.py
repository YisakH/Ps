import string

def solution(msg):
    answer = []
    alpha = string.ascii_uppercase
    
    dict = { alpha[i]: i + 1 for i in range(len(alpha))}
    
    i = 0
    while i < len(msg):
        j = i + 1
        while j <= len(msg) and msg[i:j] in dict:
            j += 1 # 이 연산 후 j는 사전에 없는 단어이거나, 가장 끝 단어
        
        if msg[i:j] not in dict:
            dict[msg[i:j]] = len(dict) + 1
        answer.append(dict[msg[i:j-1]])
        i = j - 1
            
    return answer