class Solution(object):
    def findThePrefixCommonArray(self, A, B):
        s = set()
        answer = [0 for _ in A]

        for i, (a, b) in enumerate(zip(A, B)):
            s.add(a)
            s.add(b)

            answer[i] = 2*(i+1) - len(s)

        return answer
        