class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        s = set()
        min_val = float('inf')

        for num in nums:
            s.add(num)
            min_val = min(min_val, num)

        if k <= min_val:
            s.add(k)
            return len(s) - 1
        else:
            return -1