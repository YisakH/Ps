def solution(k, ranges):
    answer = []
    collatz = [k]
    
    while k > 1:
        if k % 2 == 0:
            k //= 2
        else:
            k = k * 3 + 1
        collatz.append(k)
    n = len(collatz)
    dim = [0]
    
    for i in range(n - 1):
        val = collatz[i]
        val += (collatz[i+1] - collatz[i])/2
        dim.append(val + dim[i])
    
    for [a, b] in ranges:
        a, b = a, n + b - 1
        if a > b:
            answer.append(-1)
        else:
            answer.append(dim[b] - dim[a])
    
    return answer