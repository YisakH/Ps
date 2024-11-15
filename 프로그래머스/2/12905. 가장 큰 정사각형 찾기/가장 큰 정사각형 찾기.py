def solution(board):
    answer = 0
    N = len(board)
    M = len(board[0])
    
    if N == 1:
        return max(board[0])
    elif M == 1:
        return max(board)[0]
    
    for i in range(1, N):
        for j in range(1, M):
            if board[i][j] == 0:
                continue
            board[i][j] = min(board[i-1][j-1], board[i-1][j], board[i][j-1]) + 1
            answer = max(answer, board[i][j])

    return answer**2