from bisect import bisect_left

class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        """
          카운트를 한다.

        """
        dic = {'a':[], 'b':[], 'c':[]}
        answer = 0

        for i, ch in enumerate(s):
            dic[ch].append(i)

        for start in range(len(s)):
            min_idx = 0
            for ch in ['a', 'b', 'c']:
                idx = bisect_left(dic[ch], start)
                if idx >= len(dic[ch]):
                    min_idx = None
                    break
                min_idx = max(min_idx, dic[ch][idx])

            if min_idx:
                answer += len(s) - min_idx
            
        
        return answer