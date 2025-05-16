from collections import defaultdict

class Solution:
    def getWordsInLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        def checkDiff(word1, word2):
            return len(word1) == len(word2) and sum(ch1 != ch2 for ch1, ch2 in zip(word1, word2)) == 1

        N = len(words)
        dp = [[1, -1] for _ in range(N)]
        
        for j in range(N):
            for i in range(j):
                if groups[i] != groups[j] and checkDiff(words[i], words[j]) == 1:
                    if dp[j][0] < dp[i][0] + 1:
                        dp[j] = [dp[i][0] + 1, i]
        
        maxidx = max(range(N), key = lambda x: dp[x][0])
        ans = []

        while maxidx != -1:
            ans.append(words[maxidx])
            maxidx = dp[maxidx][1]

        return ans[::-1]