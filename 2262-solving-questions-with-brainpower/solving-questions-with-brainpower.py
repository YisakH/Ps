from collections import defaultdict

class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        dp = defaultdict(int)
        answer = 0

        for i, (point, bp) in enumerate(questions):
            dp[i + bp + 1] = max(dp[i + bp + 1], dp[i] + point)
            dp[i+1] = max(dp[i], dp[i+1])

            answer = max(answer, dp[i + bp + 1])

        return answer