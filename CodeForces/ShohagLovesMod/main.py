
for _ in range(int(input())):
    n = int(input())
    gap = 2
    cur = 1
    print(1, end=' ')
    for i in range(n - 1):
        print(cur + gap, end=' ')
        cur += gap
    print()
    