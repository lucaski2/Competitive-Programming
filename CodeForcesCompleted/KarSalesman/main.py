from math import ceil
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    print(max(max(a), ceil(sum(a) / k)))