from collections import defaultdict

class Solution:
    def getWordsInLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        def checkDiff(word1, word2):
            if len(word1) != len(word2):
                return -1
        
            res = 0
            
            for ch1, ch2 in zip(word1, word2):
                if ch1 != ch2:
                    res += 1
            
            return res

        N = len(words)
        dp = [[1, -1] for _ in range(N)]
        
        for j in range(N):
            for i in range(j):
                if groups[i] != groups[j] and checkDiff(words[i], words[j]) == 1:
                    if dp[j][0] < dp[i][0] + 1:
                        dp[j] = [dp[i][0] + 1, i]
        
        maxidx = 0
        ans = []

        for i in range(N):
            if dp[maxidx][0] < dp[i][0]:
                maxidx = i

        while maxidx != -1:
            ans.append(words[maxidx])
            maxidx = dp[maxidx][1]
        ans.reverse()
        
        return ans