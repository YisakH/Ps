from collections import deque

class Solution:
    def maxFreeTime(self, eventTime: int, k: int, startTime: List[int], endTime: List[int]) -> int:
        # k 개를 옮긴다? 결국 연속 k개 사이에 있는 쉬는시간의 합을 구하라 문제
        #startTime = [0] + starTime
        #endTime = [0] + endTime
        ans = 0
        cur_sum = startTime[0]
        i = 0

        for j in range(1, len(startTime)):
            cur_sum += startTime[j] - endTime[j-1]
            ans = max(ans, cur_sum)

            if j - i + 1 > k:
                if i > 0:
                    cur_sum -= startTime[i] - endTime[i-1]
                else:
                    cur_sum -= startTime[i]
                i += 1
        
        ans = max(ans, cur_sum + eventTime - endTime[-1])
        
        return ans
