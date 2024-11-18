
n = int(input())
a = list(map(int, input().split()))

divisors = [[] for i in range(100001)]

for i in range(2, 100000):
    if len(divisors[i]) == 0:
        for j in range(i, 100001, i):
            divisors[j].append(i)


for i in range(2, 100001):
    if len(divisors[i]) == 0:
        divisors[i].append(i)
    
dp = [0] * n
dp[0] = 1

nearest = {}
for divisor in divisors[a[0]]:
    nearest[divisor] = 0

for i in range(1, n):
    dp[i] = 1
    for divisor in divisors[a[i]]:
        if divisor in nearest:
            dp[i] = max(dp[i], dp[nearest[divisor]] + 1)
        nearest[divisor] = i

print(max(dp))




