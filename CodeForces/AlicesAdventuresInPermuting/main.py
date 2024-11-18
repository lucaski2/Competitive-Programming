
for _ in range(int(input())):
    n, b, c = map(int, input().split())
    if b == 0 and c < n - 2:
        print(-1)
        continue
    if b == 0:
        if c < n:
            print(n - 1)
        else:
            print(n)
        continue
    am = max(0, (n - c + b - 1) // b)
    # if ((n - 1) - c) % b == 0 and :
    #     am += 1 
    print(n - am)