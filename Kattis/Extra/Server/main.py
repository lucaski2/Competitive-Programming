length, T = list(map(int, input().split()))
lst = list(map(int, input().split()))

count = 0
for i in range(length):
    if lst[i] > T:
        print(i)
        break
    else:
        T -= lst[i]
        count += 1
else:
    print(count)