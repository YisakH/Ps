class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        mod = 10**9 + 7
        even, odd = 1, 0  # 초기 누적합 0은 짝수로 간주 -> even 초기값 1
        prefix = 0
        answer = 0

        for num in arr:
            prefix += num
            if prefix & 1:
                # 현재 누적합이 홀수라면, 이전 짝수 누적합과의 차로 홀수 합을 만들 수 있음
                answer = (answer + even) % mod
                odd += 1
            else:
                answer = (answer + odd) % mod
                even += 1

        return answer