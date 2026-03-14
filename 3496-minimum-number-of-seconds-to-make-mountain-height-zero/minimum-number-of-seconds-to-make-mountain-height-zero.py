from math import sqrt

class Solution:
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: List[int]) -> int:

        l = 1
        r = 5000050000000000

        while l < r:
            m = (l + r) // 2 # 이 시간안에 할 수 있나?
            total = 0

            for w in workerTimes:
                x = (-1 + sqrt(1 + 4 * (2*m/w))) / 2

                total += floor(x)

            if total >= mountainHeight:
                r = m
            else:
                l = m + 1
        return r