
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(input())
    cur_count = 0
    ans = 0
    for i in range(n):
        if a[i] == "B" and cur_count <= 0:
            ans += 1
            cur_count = k - 1
        else:
            cur_count -= 1
    print(ans)
