
for _ in range(int(input())):
    n, k = map(int, input().split())
    s1 = list(map(int, list(input())))
    s2 = list(map(int, list(input())))
    if s1.count(0) != s2.count(0):
        print("NO")
        continue
    ans = 0
    for i in range(n):
        if s1[i] != s2[i] and s1[i] == 0:
            ans += 1
    print("YES" if ans <= k and ((ans - k) % 2 == 0 or s1.count(0) > 1 or s2.count(1) > 1) else "NO")