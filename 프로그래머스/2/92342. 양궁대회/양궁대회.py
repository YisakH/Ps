
def solution(n, info):
    def getScore(aArr, rArr):
        aScore, rScore = 0, 0
        for i, (a,r) in enumerate(zip(aArr,rArr)):
            if r:
                rScore += 10 - i
            elif a:
                aScore += 10 - i
        return rScore - aScore
    
    def func(aArr, bArr):
        for a, b in zip(aArr[::-1], bArr[::-1]):
            if b:
                return True
            elif a:
                return False
    
    answer = [-1]
    answer_score = 0
    
    st = []
    visit = [False for _ in range(11)]
    st.append((n, visit.copy(), 0))
    
    while st:
        _n, _visit, _index = st.pop()
        
        if _index == len(_visit) - 1: # 11번째는 0점이기 때문에 방문필요 없음
            score = getScore(info, _visit)
            if answer_score < score or answer_score == score and func(answer, _visit):
                answer_score = score
                answer = _visit.copy()
            continue
        
        st.append((_n, _visit.copy(), _index + 1))
        
        if _n > info[_index]:
            _visit[_index] = True
            _n -= info[_index] + 1
            st.append((_n, _visit.copy(), _index + 1))

    
    answer = [info[i] + 1 if val else 0 for i, val in enumerate(answer)]
    if len(answer) == 1:
        return [-1]
    elif sum(answer) < n:
        answer[-1] = n-sum(answer)
    return answer