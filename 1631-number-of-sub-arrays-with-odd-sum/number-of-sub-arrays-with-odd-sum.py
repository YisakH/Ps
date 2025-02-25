class Solution:
    def numOfSubarrays(self, acc_sum: List[int]) -> int:
        # 홀수와 인덱스를 센다
        #acc_sum = arr.copy()

        for i in range(1, len(acc_sum)):
            acc_sum[i] += acc_sum[i-1]

        o_cnt, e_cnt = 0, 0
        answer = 0

        for i, val in enumerate(acc_sum):
            if val % 2:
                answer = (answer + (1 + e_cnt)) % (10**9 + 7)
                o_cnt += 1
            else:
                answer = (answer + o_cnt) % (10**9 + 7)
                e_cnt += 1

        return answer

        