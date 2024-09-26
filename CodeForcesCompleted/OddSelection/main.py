
for _ in range(int(input())):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    odd, even = 0, 0
    for i in a:
        if i % 2 == 0:
            even += 1
        else:
            odd += 1
    if odd == 0:
        print("No")
        continue
    if even == 0 and x % 2 == 0:
        print("No")
        continue
    odd = min(x, odd) if odd % 2 == 1 else min(x, odd - 1)
    if odd + even >= x:
        print("Yes")
    else:
        print("No")