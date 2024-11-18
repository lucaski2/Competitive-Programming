for _ in range(int(input())):
    n, k = map(int, input().split())
    # convert n into base k
    highest = 0
    if k == 1:
        print(n)
        continue
    while k ** highest <= n:
        highest += 1
    ans = 0
    for i in range(highest, -1, -1):
        amount = n // k ** i
        n -= amount * k ** i
        ans += amount
        
    print(ans)