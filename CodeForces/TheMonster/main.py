a, b = map(int, input().split())
c, d = map(int, input().split())

cur_time1 = b 
cur_time2 = d

for i in range(500000):
    if cur_time1 == cur_time2:
        print(cur_time1)
        break
    elif cur_time1 < cur_time2:
        cur_time1 += a
    else:
        cur_time2 += c
else:
    print(-1)

