
n, a = map(int, input().split())

people = list(map(int, input().split()))

cur_time = 0
for p in people:
    if cur_time < p:
        cur_time = p
    cur_time += a
    print(cur_time)



