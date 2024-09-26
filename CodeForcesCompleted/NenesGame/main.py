
for _ in range(int(input())):
    k, q = map(int, input().split())
    a = list(map(int, input().split()))
    n = list(map(int, input().split()))
    m = min(a)
    for i in range(q):
        print(min(n[i], m - 1), end=" ")
    print()