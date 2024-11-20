def solution(plans):
    answer = []
    plans.sort(key=lambda x:x[1])
    
    for i, s in enumerate(plans):
        [sh, sm] = map(int, s[1].split(':'))
        plans[i][1] = sh*60 + sm
        plans[i][2] = int(s[2])
    
    st = []
    cur_time = plans[0][1]
    
    for plan in plans:
        while st and cur_time + st[-1][2] < plan[1]: # 쌓여있는 과제들 끝내기
            s = st.pop()
            answer.append(s[0])
            cur_time += s[2]
        if st and cur_time + st[-1][2] == plan[1]: # 끝나자마자 시작
            answer.append(st.pop()[0])
        if st: # 기존 과제 있는데 새로운 과제 시작 -> 남은 시간 업데이트
            st[-1][2] = cur_time + st[-1][2] - plan[1]
            
        st.append(plan)
        cur_time = max(cur_time, plan[1])
    
    while st:
        answer.append(st.pop()[0])
    
    return answer