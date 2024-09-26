
for _ in range(int(input())):
    n = int(input())
    n2 = n
    m = 4

    while n > 0:
        m = min(m, n % 3)
        m = min(m, n2 % 5)
        n -= 5
        n2 -= 3
    
    print(m)
        