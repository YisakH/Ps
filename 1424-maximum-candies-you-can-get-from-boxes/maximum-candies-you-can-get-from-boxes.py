from collections import deque

class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        haveKeys = set()
        answer = 0
        noKeys = deque()
        boxQ = deque(initialBoxes)

        while boxQ or noKeys:
            opened = False
            while boxQ:
                b = boxQ.popleft()

                if status[b] or b in haveKeys:
                    answer += candies[b]
                    for k in keys[b]:
                        haveKeys.add(k)
                    for c in containedBoxes[b]:
                        boxQ.append(c)
                    opened = True
                else:
                    noKeys.append(b)
            
            while noKeys:
                b = noKeys.popleft()

                if status[b] or b in haveKeys:
                    answer += candies[b]
                    for k in keys[b]:
                        haveKeys.add(k)
                    for c in containedBoxes[b]:
                        noKeys.append(c)
                    opened = True
                else:
                    boxQ.append(b)

            if not opened:
                break

        return answer


