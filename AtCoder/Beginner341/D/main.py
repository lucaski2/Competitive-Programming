
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def lcm(x, y):
    return (x * y) // gcd(x, y)

n, m, k = map(int, input().split())
l = lcm(n, m)
time_before_gcd = l // n + l // m - 2
cur_num = 0
am = k // time_before_gcd
k %= time_before_gcd
cur_num += am * l
if k == 0:
    k = time_before_gcd
    cur_num -= l
    

until_n, until_m = n, m
while k > 0:
    k -= 1
    cur_num += min(until_n, until_m)
    until_n, until_m = until_n - min(until_n, until_m), until_m - min(until_n, until_m)
    if until_n == 0:
        until_n = n
    else:
        until_m = m
print(cur_num)

