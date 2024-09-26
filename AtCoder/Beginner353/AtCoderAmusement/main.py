n, k = map(int, input().split())

lst = list(map(int, input().split()))
rides = 0
cur_amount = 0
for i in lst:
    if i > k - cur_amount:
        rides += 1
        cur_amount = 0
    cur_amount += i

print(rides + 1)

