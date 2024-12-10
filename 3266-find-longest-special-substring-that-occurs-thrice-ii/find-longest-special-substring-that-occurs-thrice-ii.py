from collections import defaultdict

class Solution:
    def maximumLength(self, s: str) -> int:
        n = len(s)
        cnt = defaultdict(int)
        i = 0
        while i < n:
            j = i
            while j < n and s[i] == s[j]:
                j += 1
            j -= 1
            
            length = j - i + 1
            for k in range(length):
                cnt[(s[i], k + 1)] += (length - k)
            i = max(j + 1, i + 1)
        
        answer = 0
        for key, val in cnt.items():
            if val >= 3:
                answer = max(answer, key[1])
        
        return answer if answer else -1