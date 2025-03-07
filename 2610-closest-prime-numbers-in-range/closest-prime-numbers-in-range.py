from math import isqrt
from typing import List

class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        if right < 2:
            return [-1, -1]
        
        # 에라토스테네스의 체: right까지의 소수 여부를 판별하는 배열 생성
        sieve = [True] * (right + 1)
        sieve[0], sieve[1] = False, False
        
        # i*i부터 시작하면 이미 i 이하의 배수는 처리되었으므로 최적화됨.
        for i in range(2, isqrt(right) + 1):
            if sieve[i]:
                for j in range(i * i, right + 1, i):
                    sieve[j] = False
        
        # left 이상 right 이하에 있는 소수들만 필터링 (단, 소수는 2 이상이어야 함)
        primes = [p for p in range(max(left, 2), right + 1) if sieve[p]]
        if len(primes) < 2:
            return [-1, -1]
        
        best_gap = float('inf')
        best_pair = [-1, -1]
        
        # 연속하는 소수들 간의 차이를 계산하여 최소 간격 쌍을 찾음
        for i in range(len(primes) - 1):
            gap = primes[i+1] - primes[i]
            if gap < best_gap:
                best_gap = gap
                best_pair = [primes[i], primes[i+1]]
                # 최소 차이가 1이면 더 이상 개선할 수 없으므로 종료
                if best_gap == 1:
                    break
        
        return best_pair