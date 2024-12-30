from collections import defaultdict

class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        answer = 0
        dp = defaultdict(int)
        dp[0] = 1

        for i in range(high):
            if i + zero <= high:
                dp[i+zero] = (dp[i] + dp[i+zero]) % (10**9 + 7)

                if low <= i + zero:
                    answer = (dp[i] + answer) % (10**9 + 7)

            if i + one <= high:
                dp[i+one] = (dp[i] + dp[i+one]) % (10**9 + 7)

                if low <= i + one:
                    answer = (dp[i] + answer) % (10**9 + 7)

        return answer
