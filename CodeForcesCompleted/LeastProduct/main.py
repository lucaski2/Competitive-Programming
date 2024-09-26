
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    s = sum([1 for i in a if i < 0])
    if 0 in a:
        print(0)
        continue
    if s % 2 == 0:
        print(1)
        print(1, 0)
    else:
        print(0)
