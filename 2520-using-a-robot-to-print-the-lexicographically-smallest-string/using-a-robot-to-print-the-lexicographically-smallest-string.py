from collections import Counter
class Solution:
    def robotWithString(self, s: str) -> str:
        count = [0 for _ in range(26)]
        for ch in s:
            count[ord(ch) - ord('a')] += 1

        t = []
        ans = []
        cntidx = 0

        for ch in s:
            count[ord(ch) - ord('a')] -= 1
            while cntidx < 26 and count[cntidx] == 0:
                cntidx += 1

            t.append(ch)
            while t and t[-1] <= chr(cntidx + ord('a')):
                ans.append(t.pop())

    
        ans += t[::-1]
        return "".join(ans)