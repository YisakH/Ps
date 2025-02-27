class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        dp = {i:[] for i in arr}
        answer = 0

        for i, num in enumerate(arr):
            for j in range(i):
                dp[num].append((arr[j], 2))

            for before, length in dp[num]:
                answer = max(answer, length)
                if num + before not in dp:
                    continue
                dp[num + before].append((num, length + 1))
            
        return answer if answer >= 3 else 0