
N = int(input())

shirts = list(map(int, input().split()))
T, P = map(int, input().split())

needT = 0

for s in shirts:
    needT += (s + T - 1) // T

print(needT)

print(N // P, N - (N // P) * P)
