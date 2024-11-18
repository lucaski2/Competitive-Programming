
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    if n == 1:
        print(a[0] + 1)
        continue
    a1 = a[::2]
    a2 = a[1::2]
    print(max(max(a1) + len(a1), max(a2) + len(a2)))