
for _ in range(int(input())):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    

    freq = [0] * n
    for i in range(n):
        if a[i] >= n:
            continue
        freq[a[i]] += 1
    
    for i in range(n):
        if freq[i] > 1:
            if i + x >= n:
                continue
            freq[i + x] += freq[i] - 1
            freq[i] = 1
    
    mex = 0
    while mex < n and freq[mex] > 0:
        mex += 1
    print(mex)


