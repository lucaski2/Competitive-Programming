
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    # check if there is anything with more than 2 occurrences
    for i in range(2, n):
        if a[i] == a[i-1] and a[i] == a[i-2]:
            print(a[i])
            break
    else:
        print(-1)