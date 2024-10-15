def solution(x, y, n):
    answer = 0
    
    dp = [float('inf') for _ in range(y + 1)]
    dp[x] = 0
    
    for i in range(x + 1, len(dp)):
        dp[i] = min(dp[i-n] + 1, dp[i])
        dp[i] = min(dp[i // 2] + 1, dp[i]) if i % 2 == 0 else dp[i]
        dp[i] = min(dp[i // 3] + 1, dp[i]) if i % 3 == 0 else dp[i]
    
    return dp[y] if dp[y] != float('inf') else -1