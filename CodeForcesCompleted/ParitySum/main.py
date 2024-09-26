
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    evens = []
    odds = []
    max_even = 0
    max_odd = 0
    for i in range(n):
        if a[i] % 2 == 0:
            evens.append(a[i])
            max_even = max(max_even, a[i])
        else:
            odds.append(a[i])
            max_odd = max(max_odd, a[i])
    if len(odds) == 0:
        print(0)
        continue

    evens.sort(reverse=True)
    odds.sort(reverse=True)
    ans = 0
    while len(evens) > 0:
        cur = evens.pop()
        if max_odd > cur:
            ans += 1
            max_odd += cur
        else:
            max_odd += max_even
            ans += 2
            max_odd += cur
    
    print(ans)



    