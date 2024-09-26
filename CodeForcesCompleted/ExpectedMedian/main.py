from math import comb


mod = 10 ** 9 + 7
mx = 2*10**5 + 1
def mod_comb(n, k):
    if n < k:
        return 0
    acc = 1
    for i in range(n-k+1, n+1):
        acc = (acc * i) % mod
    for i in range(1, k+1):
        acc = acc * pow(i, mod-2, mod) % mod
    return acc

lookup = [0 for _ in range(mx)]
for i in range(mx):
    lookup[i] = pow(i, mod-2, mod)
# print(lookup[:20])
for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    # if _ != 3:
    #     continue
    ones = a.count(1)
    zeros = a.count(0)
    start_ind = 1
    while ones < k - start_ind + 1 or zeros < start_ind - 1:
        start_ind += 1
        if start_ind > k // 2 + 1:
            print(0)
            break
    else:
        last = comb(ones, k - start_ind + 1) * comb(zeros, start_ind - 1) % mod
        ans = last
        # print(ones, k - start_ind + 1)
        # print(zeros, start_ind - 1)
        for i in range(start_ind, k // 2 + 1):
            # if k - i > ones or i + 1 > zeros:
            #     break
            last *= (k-i+1)*lookup[ones-k+i]*(zeros-i+1)*lookup[i]

            last %= mod
            ans += last
            ans %= mod
        print(ans)




