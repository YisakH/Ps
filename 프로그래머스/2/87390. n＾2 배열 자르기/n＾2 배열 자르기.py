def get_xy(n, num):
    return num//n, num%n

def get_val(y, x):
    return max(x, y) + 1

def solution(n, left, right):
    answer = []
    
    for num in range(left, right + 1):
        y, x = get_xy(n, num)
        answer.append(get_val(y, x))
    
    return answer