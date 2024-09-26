cur = []
for _ in range(int(input())):
    a, b = map(int, input().split())
    if a == 1:
        cur.append(b)
    else:
        print(cur[len(cur) - b])
