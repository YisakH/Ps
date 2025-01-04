from collections import defaultdict

class Solution(object):
    def countPalindromicSubsequence(self, s):
        dic = defaultdict(list)
        answer = 0

        for i, ch in enumerate(s):
            dic[ch].append(i)
        
        for key, val in dic.items():
            if len(val) > 1 and val[-1] - val[0] >= 2:
                myset = set([ch for ch in s[val[0] + 1: val[-1]]])
                answer += len(myset)
        
        return answer