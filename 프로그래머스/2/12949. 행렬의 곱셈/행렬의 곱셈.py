def solution(arr1, arr2):
    n, l, m = len(arr1), len(arr1[0]), len(arr2[0])
    answer = [[0 for _ in range(m)] for _ in range(n)]
    
    for i in range(n):
        for j in range(m):
            for k in range(l):
                answer[i][j] += arr1[i][k] * arr2[k][j]
    
    return answer