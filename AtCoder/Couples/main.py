n = int(input())

lst = list(map(int, input().split()))

cnt = 0

for i in range(n * 2 - 2):
    if lst[i] == lst[i + 2]:
        cnt += 1

print(cnt)