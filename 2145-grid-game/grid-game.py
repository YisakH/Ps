class Solution(object):
    def gridGame(self, grid):
        N = len(grid[0])
        answer = float('inf')
        low_sum, up_sum = 0, sum(grid[0])

        for i in range(N):
            if i != 0:
                low_sum += grid[1][i-1]
                
            up_sum -= grid[0][i]
            answer = min(answer, max(up_sum, low_sum))

        return answer