def dfs(picks, minerals):
    st = [(picks.copy(), minerals, 0, 0)]
    pick_w = [25, 5, 1]
    need_w = {"diamond":25, 'iron':5, 'stone':1}
    minimum = float('inf')
    
    while st:
        [my_picks, mineral, cur_index, tired] = st.pop()
        if tired >= minimum:
            continue
        
        for select in range(3):
            new_tired = tired
            my_picks[select] -= 1
            if my_picks[select] < 0:
                my_picks[select] += 1
                continue
            
            for m in range(cur_index, min(len(mineral), cur_index + 5)):
                new_tired += max(need_w[mineral[m]] // pick_w[select], 1)
            
            if (cur_index + 5 >= len(mineral)):
                minimum = min(new_tired, minimum)
            else:
                st.append([my_picks.copy(), mineral, cur_index + 5, new_tired])
            
            my_picks[select] += 1
            
    return minimum

def solution(picks, minerals):
    answer = 0
    [dia, iron, stone] = picks
    # 종료 조건을 모든 미네랄을 다 캐는 경우로 단순화. 즉, 미네랄 수 <= 곡괭이 수 * 5
    minerals = minerals[:min((dia+iron+stone) * 5, len(minerals))]

    return dfs(picks, minerals)