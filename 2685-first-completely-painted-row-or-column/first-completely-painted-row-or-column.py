class Solution(object):
    def firstCompleteIndex(self, arr, mat):
        M = len(mat)
        N = len(mat[0])
        index = [(-1, -1) for _ in range(M*N + 1)]

        for i in range(M):
            for j in range(N):
                index[mat[i][j]] = (i, j)

        row_cnt = [0 for _ in range(M)]
        col_cnt = [0 for _ in range(N)]

        for i, num in enumerate(arr):
            row, col = index[num]
            row_cnt[row] += 1
            col_cnt[col] += 1

            if row_cnt[row] == N or col_cnt[col] == M:
                return i
        
        return -1
        