
for _ in range(int(input())):
    n, s, m = map(int, input().split())
    intervals = [list(map(int, input().split())) for _ in range(n)]

    if intervals[0][0] >= s:
        print("YES")
        continue
    
    for i in range(n):
        if i == n - 1:
            if m - intervals[i][1] >= s:
                print("YES")
                break
        else:
            if intervals[i + 1][0] - intervals[i][1] >= s:
                print("YES")
                break
    else:
        print("NO")