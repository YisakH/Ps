from collections import Counter

class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        count = Counter(digits)
        start, mid, end = [], [], []
        
        for key, val in count.items():
            val = min(val, 3)
            count[key] = val

            mid.append(key)

            if key == 0:
                end.append(key)
            elif key % 2 == 0:
                start.append(key)
                end.append(key)
            else:
                start.append(key)
        
        answer = []
        
        for e in end:
            count[e] -= 1

            for s in start:
                if count[s] == 0:
                    continue
                count[s] -= 1

                for m in mid:
                    if count[m] == 0:
                        continue
                    
                    answer.append(int(str(s) + str(m) + str(e)))

                count[s] += 1

            count[e] += 1

        answer.sort()
        return answer