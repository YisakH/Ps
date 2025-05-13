from collections import Counter

class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        count = Counter(s)
        answer = len(s)
        summ = [0 for _ in range(26)]

        for key, val in count.items():
            idx = ord('z') - ord(key) - 1
            summ[(idx + 1) % 26] += val

        for i in range(t):
            j = i % 26
            if summ[j] > 0:
                answer =  (answer + summ[j])  % (10 ** 9 + 7)
                summ[(j + 25) % 26] = (summ[(j + 25) % 26] + summ[j])  % (10 ** 9 + 7)

        return answer
            


