class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        N, M = len(matrix), len(matrix[0])
        rows_init = any(matrix[i][0] == 0 for i in range(N))
        cols_init = any(matrix[0][j] == 0 for j in range(M))


        for i in range(N):
            for j in range(M):
                if matrix[i][j] == 0:
                    matrix[i][0] = 'c'
                    matrix[0][j] = 'c'
        
        for i in range(1, N):
            if matrix[i][0] == 'c':
                for j in range(M):
                    matrix[i][j] = 0
        
        for j in range(1, M):
            if matrix[0][j] == 'c':
                for i in range(N):
                    matrix[i][j] = 0

        if rows_init:
            for i in range(N):
                matrix[i][0] = 0

        if cols_init:
            for j in range(M):
                matrix[0][j] = 0