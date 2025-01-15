class Solution(object):
    def findThePrefixCommonArray(self, A, B):
        a_set = set()
        b_set = set()
        answer = [0 for _ in A]

        for i, (a, b) in enumerate(zip(A, B)):
            a_set.add(a)
            b_set.add(b)

            answer[i] = len(a_set & b_set)

        return answer
        