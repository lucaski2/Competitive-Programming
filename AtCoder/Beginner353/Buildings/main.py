n = int(input())
lst = list(map(int, input().split()))

largest = lst[0]
for i in range(1, n):
    if lst[i] > largest:
        print(i + 1)
        exit()
print(-1)