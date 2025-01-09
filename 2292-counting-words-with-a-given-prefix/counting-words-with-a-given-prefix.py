class Solution(object):
    def prefixCount(self, words, pref):
        answer = 0
        for word in words:
            if word.startswith(pref):
                answer += 1

        return answer
