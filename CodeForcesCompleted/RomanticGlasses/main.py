
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    diffs = set()

    cur_odd = 0
    cur_even = 0
    diffs.add(0)

    for i in range(n):
        if i % 2 == 0:
            cur_even += a[i]
        else:
            cur_odd += a[i]

        if cur_odd - cur_even in diffs:
            print("YES")
            break
        else:
            diffs.add(cur_odd - cur_even)
    else:
        print("NO")




