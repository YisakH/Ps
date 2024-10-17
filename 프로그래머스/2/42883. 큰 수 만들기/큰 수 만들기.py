def solution(number, k):
    st = []
    N = len(number)
    
    for i, num in enumerate(number):
        
        while st and st[-1] < num and N - i + len(st) > N - k:
            st.pop()
        
        if len(st) < N - k:
            st.append(num) 
        
    return "".join(st)
    
    """answer = ''
    N = len(number)
    start = 0
    
    for i in range(N - k):
        ch = max(number[start:k + i + 1])
        answer += ch
        start = start + number[start:k+i+1].find(ch) + 1
    
    return answer
    """