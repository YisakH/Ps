from collections import deque

class Solution:
    def maxFreeTime(self, eventTime: int, k: int, startTime: List[int], endTime: List[int]) -> int:
        # k 개를 옮긴다? 결국 연속 k개 사이에 있는 쉬는시간의 합을 구하라 문제
        ans = 0
        cur_sum = 0


        q = deque([[0,0]])

        for s, e in zip(startTime, endTime):
            cur_sum += s - q[-1][1]
            ans = max(ans, cur_sum)
            q.append([s, e])

            if len(q) > k + 1:
                qs, qe = q.popleft()
                cur_sum -= q[0][0] - qe
        
        ans = max(ans, cur_sum + eventTime - q[-1][1])
        
        return ans
