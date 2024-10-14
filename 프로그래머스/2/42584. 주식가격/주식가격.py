def solution(prices):
    answer = [0 for _ in range(len(prices))]
    st = [] # 스택은 오름차순 저장. 저장된 값은 인덱스
    
    for i in range(len(prices)):
        while st and prices[st[-1]] > prices[i]:
            cur = st.pop()
            answer[cur] = i - cur
        
        st.append(i)
    
    while st:
        cur = st.pop()
        answer[cur] = len(prices) - 1 - cur
            
    return answer