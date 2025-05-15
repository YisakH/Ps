class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        N = len(words)
        before = -1
        answer = []

        for i in range(N):
            if before != groups[i]:
                answer.append(words[i])
                before = groups[i]

        return answer