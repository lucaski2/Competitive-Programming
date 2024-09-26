
cur = {}
q = int(input())
for i in range(q):
    a = list(map(int, input().split()))
    if a[0] == 3:
        print(len(cur))
    elif a[0] == 2:
        cur[a[1]] -= 1
        if cur[a[1]] == 0:
            del cur[a[1]]
    else:
        if a[1] not in cur:
            cur[a[1]] = 1
        else:
            cur[a[1]] += 1

