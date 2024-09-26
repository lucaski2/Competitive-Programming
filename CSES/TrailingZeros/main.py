n = int(input())
cur = 5
ans = 0
while cur <= n:
    ans += n // cur
    cur *= 5

print(ans)
