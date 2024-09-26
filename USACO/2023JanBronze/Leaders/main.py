n = int(input())
s = list(input())
a = list(map(int, input().split()))
for i in range(n):
    a[i] -= 1

start_g = False
start_h = False
first_h = s.index("H")
last_h = n - s[::-1].index("H") - 1
if a[first_h] >= last_h:
    start_h = True

first_g = s.index("G")
last_g = n - s[::-1].index("G") - 1
if a[first_g] >= last_g:
    start_g = True

ans = 1 if start_g == start_h == True else 0

if start_g:
    for i in range(first_g):
        if s[i] == "H" and a[i] >= first_g:
            ans += 1


if start_h:
    for i in range(first_h):
        if s[i] == "G" and a[i] >= first_h:
            ans += 1

print(ans)
