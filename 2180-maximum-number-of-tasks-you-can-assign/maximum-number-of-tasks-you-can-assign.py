from collections import deque
from bisect import bisect_left

class Solution(object):
    def maxTaskAssign(self, tasks, workers, pills, strength):
        tasks.sort()
        workers.sort()

        def can(k):
            if k == 0:
                return True
            stasks = tasks[:k]
            sworkers = workers[-k:]
            pills_left = pills

            for task in reversed(stasks):

                if task <= sworkers[-1]:
                    sworkers.pop()
                
                elif pills_left:
                    idx = bisect_left(sworkers, task - strength)
                    pills_left -= 1
                    if 0<= idx < len(sworkers):
                        sworkers.pop(idx)
                    else:
                        return False
                
                else:
                    return False
                
            return True
        
        l, r = 0, min(len(workers), len(tasks))

        while l <= r:
            m = (l + r) // 2

            if can(m):
                l = m + 1
            else:
                r = m - 1
        
        return l - 1



