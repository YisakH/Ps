
def dfs(depth, users, emoticons, spend):
    
    if depth == len(emoticons):
        plus, total_sum = 0, 0
        for i in range(len(users)):
            if (users[i][1] <= spend[i]):
                plus += 1
            else:
                total_sum += spend[i]

        return [plus, total_sum]

    discount = [10, 20, 30, 40]
    max_p, max_t = 0, 0
    
    for disc in discount:
        diff = [0 for _ in users]
        for i, (udisc, _) in enumerate(users):
            
            if udisc <= disc:
                diff[i] += emoticons[depth] * (100 - disc) // 100
        
        p, t = dfs(depth + 1, users, emoticons, [s + d for s, d in zip(spend, diff)])
        
        if max_p <  p:
            max_p, max_t = p, t
        elif max_p == p and max_t < t:
            max_p, max_t = p, t
            
    return [max_p, max_t]

def solution(users, emoticons):
    return dfs(0, users, emoticons, [0 for _ in users])