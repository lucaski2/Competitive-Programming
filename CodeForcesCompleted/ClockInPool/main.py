
for _ in range(int(input())):
    k, m = map(int, input().split())
    cur = m // k
    if cur % 3 == 2:
        print(0)
    elif cur % 3 == 0:
        print(k - m % k + k)
    else:
        print(k - m % k)