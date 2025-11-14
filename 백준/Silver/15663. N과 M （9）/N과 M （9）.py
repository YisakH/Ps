from itertools import permutations

N, M = map(int, input().split())
arr = list(map(int, input().split()))

arr.sort()
permutation = permutations(arr, M)
visit = set()

for p in permutation:
    if p in visit:
        continue
    visit.add(p)
    ans = ""
    for n in p:
        ans += str(n) + " "
    print(ans[:-1])
