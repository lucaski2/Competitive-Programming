
for _ in range(int(input())):
    n, q = map(int, input().split())
    a = list(map(int, input().split()))

    num_ones = [0]
    sum_below = [0]
    for i in range(n):
        num_ones.append(num_ones[-1] + int(a[i] == 1))
        sum_below.append(sum_below[-1] + a[i] - 1)
    
    for _ in range(q):
        a, b = map(int, input().split())
        s_below = sum_below[b] - sum_below[a - 1]
        s_ones = num_ones[b] - num_ones[a - 1]
        if s_below >= s_ones and b - a != 0:
            print("YES")
        else:
            print("NO")
