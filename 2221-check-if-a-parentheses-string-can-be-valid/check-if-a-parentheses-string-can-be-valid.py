# 1. 총 열린 수와 닫힌 수가 같아야 한다
# 2. 어느 시점에 닫힌 수가 열린 수보다 많으면 안된다

class Solution(object):
    def canBeValid(self, s, locked):
        if len(s) % 2 != 0:
            return False
        
        opened = []
        nothing = []

        for i, ch in enumerate(s):
            if locked[i] == '1':
                if ch == '(':
                    opened.append(i)
                else:
                    if opened:
                        opened.pop()
                    elif nothing:
                        nothing.pop()
                    else:
                        return False
            else:
                nothing.append(i)

        while opened and nothing and opened[-1] < nothing[-1]:
            opened.pop()
            nothing.pop()
        
        return False if opened else True