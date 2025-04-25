class Solution(object):
    def countInterestingSubarrays(self, nums, modulo, k):
        dic = defaultdict(int)
        # PS[-1] = 0 이고, (0 + k) % m 값으로 한 개 있다고 미리 세워두기
        dic[(0 + k) % modulo] = 1

        PS = 0
        ans = 0

        for x in nums:
            if x % modulo == k:
                PS += 1
            p = PS % modulo

            # 조회는 그대로 p
            ans += dic[p]

            # 저장은 (p + k) % m 로
            dic[(p + k) % modulo] += 1

        return ans