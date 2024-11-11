def add_10m(h, m):
    m += 10
    h += m // 60
    m %= 60
    return h, m

def cal_diff(h1, m1, h2, m2):
    return (h1-h2) * 60 + m1 - m2

def solution(book_time):
    room_list = []
    book_time.sort(key= (lambda x:x[0]))
    
    for [start, end] in book_time:
        [sh, sm] = map(int, start.split(':'))
        [eh, em] = map(int, end.split(':'))
        eh, em = add_10m(eh, em)
        
        index = 0
        min_index = -1
        min_diff = float('inf')
        
        while (index < len(room_list)):
            rh, hm = room_list[index]
            
            diff = cal_diff(sh, sm, rh, hm)
            if (diff >= 0 and diff < min_diff):
                min_diff = diff
                min_index = index
            
            index += 1
        
        if min_index == -1: # 들어갈 방이 없는 경우
            room_list.append([eh, em])
        else:
            room_list[min_index] = [eh, em]
        
    
    return len(room_list)
        
        
        