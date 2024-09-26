
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    if n == 2:
        print(min(a))
        continue
    print(max(a[1:-1]))