def solution(land):
    answer = 0
    dp = [row[:] for row in land] 
    
    for i in range(1, len(land)):
        for j in range(4):
            for k in range(4):
                if j == k:
                    continue
                dp[i][j] = max(dp[i][j], dp[i-1][k] + land[i][j])

    return max(dp[-1])