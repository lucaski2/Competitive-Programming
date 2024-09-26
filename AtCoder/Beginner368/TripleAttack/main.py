
n = int(input())

a = list(map(int, input().split()))
k = 0

for i in range(n):
    am = (a[i] // 5) * 3
    a[i] %= 5
    if a[i] == 0:
        k += am
        continue
    if k % 3 == 2 and a[i] <= 3:
        k += 1
    elif k % 3 == 2:
        k += a[i] - 3 + 1
    elif k % 3 == 1 and a[i] == 1:
        k += 1
    elif k % 3 == 1 and a[i] <= 4:
        k += 2
    elif k % 3 == 1:
        k += 3
    elif k % 3 == 0 and a[i] <= 2:
        k += a[i]
    else:
        k += 3
    k += am
    
    
print(k)



