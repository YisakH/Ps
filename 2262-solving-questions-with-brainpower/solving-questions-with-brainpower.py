from collections import defaultdict

class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        N = len(questions)
        dp = [0 for _ in range(N + 1)]
        answer = 0

        for i, (point, bp) in enumerate(questions):
            if i + bp < N:
                dp[i + bp + 1] = max(dp[i + bp + 1], dp[i] + point)
            else:
                dp[N] = max(dp[i] + point, dp[N])
            
            dp[i+1] = max(dp[i], dp[i+1])

        #print(dp)
        return dp[N]