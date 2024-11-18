from math import gcd, sqrt

max_num = 61

factors = [{} for _ in range(max_num)]
factors[1] = {1:1}
for i in range(2, max_num):
    if not factors[i]:
        for j in range(i, max_num, i):
            factors[j][i] = 1

coprimes = [0 for _ in range(max_num)]

for i in range(1, max_num):
    
    cur = i
    coprimes[i] = 1
    
    while cur > 1:
        for factor in factors[i]:
            if cur % factor == 0:
                cur //= factor
                factors[i][factor] += 1
    

    for key in factors[i]:
        factors[i][key] -= 1
        coprimes[i] *= (key - 1)
        coprimes[i] *= key ** (factors[i][key] - 1)


pref = [0]

for i in range(1, max_num):
    pref[i] = pref[i - 1] + coprimes[i]


















