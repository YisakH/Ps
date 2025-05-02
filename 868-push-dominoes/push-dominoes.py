class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        dominoes = ['L'] + list(dominoes) + ['R']
        N = len(dominoes)
        i = 0

        for j in range(1, N):
            if dominoes[j] == '.':
                continue
            
            if dominoes[i] == 'R' and dominoes[j] == 'L':
                dist = (j - i + 1) // 2
            
                for k in range(i, i + dist):
                    dominoes[k] = dominoes[i]

                for k in range(j, j - dist, -1):
                    dominoes[k] = dominoes[j]
            
            elif dominoes[i] == dominoes[j]:
                for k in range(i, j):
                    dominoes[k] = dominoes[i]
            
            i = j
                 

        return "".join(dominoes[1:-1])