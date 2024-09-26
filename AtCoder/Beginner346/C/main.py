n, k = map(int, input().split())
lst = list(sorted(list(set(map(int, input().split())))))
s = 0

for i in range(len(lst)):
    if lst[i] > k:
        break
    s -= lst[i]
try:
    s += (1 + k) * k // 2
    print(s)
except:
    print(0)



