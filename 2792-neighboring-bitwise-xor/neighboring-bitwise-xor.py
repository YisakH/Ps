class Solution(object):
    def doesValidArrayExist(self, derived):
        answer = 0
        print(derived.count(1))

        if derived.count(1) % 2:
            return False
        else:
            return True