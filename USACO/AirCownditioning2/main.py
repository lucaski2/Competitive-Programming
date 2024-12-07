
import itertools

def does_work(conditioners_in_use, num_conditioners, cows, conditioners):
    price = 0
    for cond in conditioners_in_use:
        cur_conditioner = conditioners[cond]
        price += cur_conditioner[3]
        for i in range(cur_conditioner[0], cur_conditioner[1] + 1):
            cows[i] -= cur_conditioner[2]
    
    return -1 if max(cows) > 0 else price


n, m = map(int, input().split())

cows = [0 for _ in range(100)]
for i in range(n):
    s, t, c = map(int, input().split())
    s -= 1
    t -= 1
    for j in range(s, t + 1):
        cows[j] = c

conditioners = [list(map(int, input().split())) for _ in range(m)]

for i in range(m):
    conditioners[i][0] -= 1
    conditioners[i][1] -= 1

ans = float('inf')

for i in range(1, m + 1):
    cur = itertools.combinations(range(m), i)
    for c in cur:
        works = does_work(c, m, cows.copy(), conditioners)
        if works != -1:
            ans = min(ans, works)

print(ans)
