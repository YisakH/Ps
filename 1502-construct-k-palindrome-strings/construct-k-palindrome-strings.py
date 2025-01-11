from collections import Counter

class Solution(object):
    def canConstruct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """
        if len(s) < k:
            return False

        count = Counter(s)
        one, zero = 0, 0
        
        for val in count.values():
            if val % 2 == 1:
                one += 1

        if one <= k:
            return True
        else:
            return False