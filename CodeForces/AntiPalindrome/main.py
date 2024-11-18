

s = list(input())
n = len(s)

ans = 0
for size in range(1, n + 1):
    for ind in range(n - size + 1):
        if s[ind: ind + size] != s[ind: ind + size][::-1]:
            ans = max(ans, size)
print(ans)
