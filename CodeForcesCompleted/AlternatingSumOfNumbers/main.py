
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    print(sum(a[::2]) - sum(a[1::2]))
    

