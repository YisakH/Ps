from collections import Counter

class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        count = Counter(s)
        answer = []
        repeat = 0

        while count and (len(count) > 1 or repeat < repeatLimit):
            keys = sorted(list(count.keys()), reverse = True)
            if repeat < repeatLimit:
                answer.append(keys[0])
                count[keys[0]] -= 1
                repeat += 1

                if not count[keys[0]]:
                    del count[keys[0]]
                    repeat = 0
            else:
                answer.append(keys[1])
                count[keys[1]] -= 1
                repeat = 0
                if not count[keys[1]]:
                    del count[keys[1]]
            
        return "".join(answer)
        