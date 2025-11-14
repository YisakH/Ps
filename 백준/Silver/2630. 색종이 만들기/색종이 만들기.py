
N = int(input())
arr = []

for _ in range(N):
    arr.append(input().split())
    
def checkTrue(arr, sy, sx, size):
    for i in range(sy, sy + size):
        for j in range(sx, sx + size):
            if arr[i][j] != arr[sy][sx]:
                return False, 0, 0
    
    return (True, 1, 0) if arr[sy][sx] == '0' else (True, 0, 1)

def dfs(arr, sy, sx, size):
    val, w, b = checkTrue(arr, sy, sx, size)
    if val:
        return w, b
    
    w1, b1 = dfs(arr, sy, sx, size // 2)
    w2, b2 = dfs(arr, sy + size // 2, sx, size // 2)
    w3, b3 = dfs(arr, sy, sx + size // 2, size // 2)
    w4, b4 = dfs(arr, sy + size // 2, sx + size // 2, size // 2)
    
    return w1 + w2 + w3 + w4, b1 + b2 + b3 + b4

w, b = dfs(arr, 0, 0, N)
print(w, b)