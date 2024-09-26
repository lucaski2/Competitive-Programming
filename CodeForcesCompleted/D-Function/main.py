MOD = 10 ** 9 + 7

def sum_of_digits(n):
    s = 0
    while n:
        s += n % 10
        n //= 10
    return s


l, r, k = 1, 10000, 4
ans = 0
for i in range(l, r + 1):
    if sum_of_digits(i) * k == sum_of_digits(k * i):
        ans += 1

# print(ans)

def solve(end, k):
    if k >= 10:
        return 0
    elif k >= 5:
        return pow(2, end, MOD)
    elif k == 4:
        return pow(3, end, MOD)
    elif k == 3:
        return pow(4, end, MOD)
    elif k == 2:
        return pow(5, end, MOD)
    else:
        return pow(10, end, MOD)


for _ in range(int(input())):
    l, r, k = map(int, input().split())
    print((solve(r, k) - solve(l, k)) % MOD)
    

        



