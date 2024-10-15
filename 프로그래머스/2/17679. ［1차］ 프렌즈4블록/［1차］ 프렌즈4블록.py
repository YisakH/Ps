from collections import deque

def solution(m, n, board):
    answer = 0
    
    board = [list(row) for row in zip(*board)]
    board = [i[::-1] for i in board]
    
    while True:
        
        delete = []
        for i in range(len(board) - 1):
            for j in range(len(board[i]) - 1):
                if (len(board[i+1]) <= j + 1):
                    continue
                    
                if board[i][j] == board[i+1][j] == board[i][j+1] == board[i+1][j+1]:
                    delete.append([i, j])
        
        if not delete:
            break

        for y, x in delete:
            board[y][x] = 'x'
            board[y+1][x] = 'x'
            board[y][x+1] = 'x'
            board[y+1][x+1] = 'x'

        board = ["".join(row) for row in board]

        for i, row in enumerate(board):
            board[i] = list(row.replace('x', ""))
    
    result_cnt = 0
    
    for row in board:
        result_cnt += len(row)        
            
    return m*n - result_cnt