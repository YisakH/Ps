def solution(data, col, row_begin, row_end):
    answer = 0
    data.sort(key=lambda x:(x[col - 1], -x[0]))
    
    for i in range(row_begin -1, row_end):
        s_i = sum(map(lambda x:x%(i+1), data[i]))
        answer = answer ^ s_i if answer != 0 else s_i
    
    return answer