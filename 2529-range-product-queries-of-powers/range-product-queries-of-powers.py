class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        binN = bin(n)[2:][::-1]
        power = []
        for i in range(len(binN)):
            if binN[i] == '1':
                power.append(i)

        for i in range(1, len(power)):
            power[i] += power[i-1]

        ans = []
        for i, j in queries:
            res = power[j]
            if i > 0:
                res -= power[i-1]
            
            ans.append((2 ** res) % (10**9 + 7) )

        return ans