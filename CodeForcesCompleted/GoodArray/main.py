n = int(input())

a = list(map(int, input().split()))
a_copy = a.copy()
a.sort()
m1, m2 = a[-1], a[-2]
s = sum(a)
ans = []
for i in range(n):
    if a_copy[i] == m1:
        if s - m1 - m2 == m2:
            ans.append(i + 1)
    else:
        if s - a_copy[i] - m1 == m1:
            ans.append(i + 1)
print(len(ans))
print(*ans)
