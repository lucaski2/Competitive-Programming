
for _ in range(int(input())):
    n, k = map(int, input().split())
    k = bin(k)[2:]
    ans = 0
    for i in range(len(k)):
        ans += pow(n, i) if k[-i-1] == '1' else 0
        ans %= 1000000007
    print(ans)