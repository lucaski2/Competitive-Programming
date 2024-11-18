
s = list(input())
n = len(s)

num_open = 0
num_close = 0
ans = 0
for i in range(n):
    if s[i] == '(':
        num_open += 1
    elif s[i] == ')':
        num_close += 1
    if num_close > num_open:
        ans += 1
        num_close -= 1

for i in range(n - 1, -1, -1):
    if num_open > num_close:
        if s[i] == '(':
            num_open -= 1
            ans += 1
    else:
        break
print(n - ans)



