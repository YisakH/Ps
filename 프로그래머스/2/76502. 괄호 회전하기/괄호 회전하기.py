from collections import deque

def solution(s):
    answer = 0
    pair = {'(':')', '[': ']', '{': '}'}
    
    q = deque()
    for c in s:
        q.append(c)
        
    for i in range(len(s)):
        c = q.popleft()
        q.append(c)
        
        stack = []
        for ch in q:
            if len(stack) == 0:
                stack.append(ch)
            elif stack[-1] in pair and pair[stack[-1]] == ch:
                stack.pop()
            else:
                stack.append(ch)
        
        if len(stack) == 0:
            answer += 1
        
    return answer