
for _ in range(int(input())):
    n = int(input())
    a = [list(input()) for i in range(n)]
    a.reverse()
    for i in range(n):
        print(a[i].index('#') + 1, end=' ')
    print()