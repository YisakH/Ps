from collections import defaultdict
from collections import deque

class Solution(object):
    def minimumLength(self, s):
        dic = defaultdict(deque)

        for i, ch in enumerate(s):
            dic[ch].append(i)

            if len(dic[ch]) >= 3:
                dic[ch].pop()
                dic[ch].popleft()
        
        return sum([len(val) for val in dic.values()])