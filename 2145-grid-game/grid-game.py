# A가 최선의 경로로 가면 무조건 정답인가?

class Solution(object):
    def gridGame(self, grid):
        N = len(grid[0])
        answer = float('inf')

        for i in range(1, N):
            grid[0][i] += grid[0][i-1]
            grid[1][i] += grid[1][i-1]

        # p idx를 선택한다는건, grid[0][idx] + (grid[1][N-1] - grid[1][idx - 1])
        # 반면 B의 입장에서는, p를 선택한 시점에서 q를 선택한다는건,
        # p보다 q가 크다면, grid[0][p+1:q+1]
        # 작다면, grid[1][:]

        for i in range(N):
            low_sum, up_sum = 0, 0

            if i is not 0: 
                low_sum = grid[1][max(i - 1, 0)]
            if i is not N - 1:
                up_sum = grid[0][N - 1] - grid[0][i]
            
            answer = min(max(up_sum, low_sum), answer)

        return answer