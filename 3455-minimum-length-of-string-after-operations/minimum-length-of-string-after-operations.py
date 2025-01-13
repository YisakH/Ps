from collections import Counter

class Solution(object):
    def minimumLength(self, s):
        cnt = Counter(s)
        answer = 0

        for val in cnt.values():
            if val % 2 == 0:
                answer += 2
            else:
                answer += 1
        
        return answer