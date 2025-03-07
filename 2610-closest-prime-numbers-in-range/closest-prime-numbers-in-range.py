from bisect import bisect_left, bisect_right
from math import sqrt

class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        prime = []
        isPrime = [True for _ in range(right + 1)]
        for i in range(2, right + 1):
            if isPrime[i]:
                prime.append(i)
                for j in range(i, right + 1, i):
                    isPrime[j] = False
        
        a = bisect_left(prime, left)
        b = bisect_right(prime, right)
        prime = prime[a:b]
        #print(prime)
        minAB = [0, 10**6]

        for i in range(len(prime) - 1):
            if prime[i+1] - prime[i] < minAB[1] - minAB[0]:
                minAB = [prime[i], prime[i+1]]
        
        return minAB if minAB[0] > 0 else [-1, -1]
