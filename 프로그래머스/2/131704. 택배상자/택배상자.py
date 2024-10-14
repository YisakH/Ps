def solution(order):
    answer = 0
    cur_index = 0
    st = []
        
    for i in range(1, len(order) + 1):
        
        while st and st[-1] == order[cur_index]:
            st.pop()
            answer += 1
            cur_index += 1
            
        if order[cur_index] == i:
            cur_index += 1
            answer += 1
        
        else:
            st.append(i)
            
    while st and st[-1] == order[cur_index]:
        st.pop()
        answer += 1
        cur_index += 1
        
    return answer