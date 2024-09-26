
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    
    
    factors_of_n = []
    for i in range(1, n):
        if n % i == 0:
            factors_of_n.append(i)
    
    ans = 0
    for factor in factors_of_n:
        sums = []
        for i in range(0, n, factor):
            cur_sum = sum(a[i:i+factor])
            sums.append(cur_sum)

        cur_max = max(sums)
        cur_min = min(sums)


        ans = max(ans, cur_max - cur_min)
    print(ans)

