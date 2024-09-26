
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    m = float('inf')
    for i in range(1, n):
        m = min(m, a[i])
    print("Bob" if m >= a[0] else "Alice")

