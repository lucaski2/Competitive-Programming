
for _ in range(int(input())):
    n, m, k = map(int, input().split())

    end_box = min(n, k), min(m, k)

    ans = end_box[0] * end_box[1]
    print(ans)