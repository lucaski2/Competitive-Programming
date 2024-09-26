
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    psum = [0]
    for i in range(n):
        psum.append(psum[-1] + a[i])
    
    # print(psum)
    ans = 0
    for i in range(n):
        if a[i] != 0:
            continue
        if abs(abs(psum[0] - psum[i + 1]) - abs(psum[n] - psum[i + 1])) == 1:
            ans += 1
        elif abs(abs(psum[0] - psum[i + 1]) - abs(psum[n] - psum[i + 1])) == 0:
            ans += 2
    print(ans)