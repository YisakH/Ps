from bisect import bisect_right

N, M = map(int, input().split())
tree = [0] + list(map(int, input().split()))
N += 1
tree.sort()
summ = tree[:]
for i in range(1, len(summ)):
    summ[i] += summ[i-1]
    
l, r, h = 1, tree[-1], -1
ans = 0
while l <= r:
    h = (l + r) // 2
    idx = bisect_right(tree, h)    
    borrow = summ[-1] - summ[idx- 1] - h * (N - 1 - idx + 1)

    if borrow >= M:
        ans = h
        l = h + 1
    elif borrow < M:
        r = h - 1

print(ans)