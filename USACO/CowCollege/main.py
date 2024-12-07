
n = int(input())
a = list(map(int, input().split()))
a.sort()

ans = 0
ans_amount = -1

for i in range(n):
    am = a[i] * (n - i)
    if am > ans:
        ans = am
        ans_amount = a[i]
print(ans, ans_amount)

