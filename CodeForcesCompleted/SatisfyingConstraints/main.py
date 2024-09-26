
for _ in range(int(input())):
    n = int(input())
    cur = [-float('inf'), float('inf')]
    not_equal = []
    for i in range(n):
        typ, a = list(map(int, input().split()))
        if typ == 3:
            not_equal.append(a)
        elif typ == 1:
            cur[0] = max(cur[0], a)
        else:
            cur[1] = min(cur[1], a)
    am = cur[1] - cur[0] + 1
    for c in not_equal:
        if c >= cur[0] and c <= cur[1]:
            am -= 1
    print(am if am > 0 else 0)


