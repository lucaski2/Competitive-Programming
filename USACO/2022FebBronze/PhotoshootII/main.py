
n = int(input())

a = list(map(int, input().split()))
b = list(map(int, input().split()))
val_index = {}
for i in range(n):
    val_index[a[i]] = i

for i in range(n):
    a[val_index[b[i]]] = i

s = 0
cur_largest = [a[0]]

for i in range(1, n):
    if a[i] > cur_largest[-1]:
        cur_largest.append(a[i])
    else:
        cur_largest.append(cur_largest[-1])

for i in range(n - 1, -1, -1):
    if a[i] < cur_largest[i]:
        s += 1

print(s)