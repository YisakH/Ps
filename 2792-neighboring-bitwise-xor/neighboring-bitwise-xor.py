class Solution(object):
    def doesValidArrayExist(self, derived):
        if derived.count(1) % 2:
            return False
        else:
            return True