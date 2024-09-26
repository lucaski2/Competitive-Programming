
for _ in range(int(input())):
    a, b, l = map(int, input().split())
    k_vals = set()

    x, y = 0, 0
    while pow(a, x) <= l:
        y = 0
        while pow(a, x) * pow(b, y) <= l:
            cur = l / (pow(a, x) * pow(b, y))
            if cur.is_integer():
                k_vals.add(int(cur))
            y += 1
        x += 1

    print(len(k_vals))



