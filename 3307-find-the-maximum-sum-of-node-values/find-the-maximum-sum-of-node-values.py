from collections import deque

class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        diff = [ (num ^ k) - num for num in nums]
        pos = [n for n in diff if n > 0]
        s = sum(nums)
        p_s = sum(pos)

        if len(pos) % 2 == 0:
            return s + p_s
        
        return s + p_s - min([abs(i) for i in diff])