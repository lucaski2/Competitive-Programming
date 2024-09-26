from math import ceil, floor
inp = open("socdist1.in", 'r')
out = open("socdist1.out", 'w')

n = int(inp.readline())

stalls = list(inp.readline().strip())

gaps = []

cur_gap = 0
for i in range(n):
    if stalls[i] == '1':
        if cur_gap != 0:
            gaps.append(cur_gap + 1)
        cur_gap = 0
    else:
        cur_gap += 1
    
if cur_gap != 0:
    gaps.append(cur_gap + 1)

ar = []
gap1 = max(gaps)
cnt = -1
cnt2 = -1

if stalls[0] == '0':
    cnt = 0
    for i in range(n):
        if stalls[i] == '0':
            cnt += 1
        else:
            break
if stalls[-1] == '0':
    cnt2 = 0
    for i in range(n - 1, -1, -1):
        if stalls[i] == '0':
            cnt2 += 1
        else:
            break

if max(cnt, cnt2) * 2 - 1 < gap1:
    cur_gap = 0

    for i in range(n):
        if stalls[i] == '1':
            cur_gap = 0
        else:
            cur_gap += 1
            if cur_gap + 1 == gap1:
                

                stalls[i - gap1 // 2] = '1'
                break

else:
    if cnt > cnt2:
        stalls[0] = '1'
    else:
        stalls[-1] = '1'

max_gap = 0
cur_gap = 0
for i in range(n):
    if stalls[i] == '0':
        cur_gap += 1
    else:
        max_gap = max(max_gap, cur_gap + 1)
        cur_gap = 0

cnt1 = -1
cnt2 = -1
if stalls[0] == '0':
    cnt = 0
    for i in range(n):
        if stalls[i] == '0':
            cnt += 1
        else:
            break
if stalls[-1] == '0':
    cnt2 = 0
    for i in range(n - 1, -1, -1):
        if stalls[i] == '0':
            cnt2 += 1
        else:
            break

if max_gap < max(cnt, cnt2) * 2 - 1:
    print(max(cnt, cnt2) - 1, file=out)

else:
    print(max_gap // 2, file=out)


print(stalls)



