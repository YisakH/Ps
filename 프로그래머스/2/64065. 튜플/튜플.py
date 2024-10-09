def solution(s):
    s = s[1:-1]
    answer = []
    start = 0
    arr = []
    
    for i, ch in enumerate(s):
        if ch == "{":
            start = i
        elif ch == "}":
            arr.append(list(map(int, s[start + 1: i].split(','))))
            
    arr.sort(key = lambda x:(len(x)))
    
    for line in arr:
        for num in line:
            if num not in answer:
                answer.append(num)
                break
    
    return answer