
for _ in range(int(input())):
    a, b = map(int, input().split())
    evens = 0
    odds = 0
    for i in range(a, b+1):
        if i % 2 == 0:
            evens += 1
        else:
            odds += 1
    c = 0
    while evens > 0 and odds > 0:
        # c += 1
        evens -= 1
        odds -= 2
        if evens >= 0 and odds >= 0:
            c += 1

    print(c)