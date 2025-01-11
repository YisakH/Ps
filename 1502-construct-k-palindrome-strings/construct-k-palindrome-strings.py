from collections import Counter

class Solution(object):
    def canConstruct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """
        N = len(s)
        if N < k:
            return False
        count = Counter(s)
        one, zero = 0, 0
        print(count)
        
        for key, val in count.items():
            if val % 2 == 0:
                zero += 1
            else:
                one += 1
        
        print(zero, one)
        if one <= k:
            return True
        else:
            return False