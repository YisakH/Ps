from collections import Counter

class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        count = Counter(nums)
        dom, remain_dom_cnt = count.most_common()[0]
        n = len(nums)
        dom_cnt = 0

        for i, val in enumerate(nums):
            if val == dom:
                dom_cnt += 1
                remain_dom_cnt -= 1

            if dom_cnt * 2 > (i + 1) and remain_dom_cnt * 2 > n - i - 1:
                return i

        return -1
