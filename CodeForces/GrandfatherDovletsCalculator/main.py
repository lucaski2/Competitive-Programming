
a, b = map(int, input().split())
ans = 0
for i in range(a, b + 1):
    digits = list(map(int, str(i)))
    for dig in digits:
        if dig == 0:
            ans += 6
        elif dig == 1:
            ans += 2
        elif dig == 2:
            ans += 5
        elif dig == 3:
            ans += 5
        elif dig == 4:
            ans += 4
        elif dig == 5:
            ans += 5
        elif dig == 6:
            ans += 6
        elif dig == 7:
            ans += 3
        elif dig == 8:
            ans += 7
        elif dig == 9:
            ans += 6
print(ans)