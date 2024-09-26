n = int(input())

a = list(map(int, input().split()))
w = list(map(int, input().split()))

d = {}

for i in range(n):
    if a[i] in d:
        d[a[i]].append(w[i])
    else:
        d[a[i]] = [w[i]]
    
s = 0
for i in d:
    s += sum(d[i])
    s -= max(d[i])



print(s)