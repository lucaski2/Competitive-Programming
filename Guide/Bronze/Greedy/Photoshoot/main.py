N = int(input())
order = input()

lst = '.'
ans = 0

for i in range(0, len(order), 2):
    if order[i] != order[i + 1]:
        if order[i] != lst:
            ans += 1
            lst = order[i]

print(ans if lst != "H" else ans - 1)