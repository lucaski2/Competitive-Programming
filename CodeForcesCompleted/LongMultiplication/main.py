
for _ in range(int(input())):
    x = input()
    y = input()
    n1 = 0
    n2 = 0
    
    for i in range(len(x)):
        cur = int(x[i]), int(y[i])
        n1 *= 10
        n2 *= 10
        if n1 >= n2:
            n1 += min(cur)
            n2 += max(cur)
        else:
            n1 += max(cur)
            n2 += min(cur)
    print(n1)
    print(n2)

