
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = []
    for i in range(0, n, 2):
        b.append(a[i])
    print(max(b))