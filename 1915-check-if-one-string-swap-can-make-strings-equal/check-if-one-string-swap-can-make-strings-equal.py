class Solution(object):
    def areAlmostEqual(self, s1, s2):
        diff = []
        for i, ch in enumerate(s1):
            if s2[i] != ch:
                diff.append(i)

        if len(diff) == 0:
            return True
        if len(diff) == 2:
            if s2[diff[0]] == s1[diff[1]] and s2[diff[1]] == s1[diff[0]]:
                return True
        
        return False