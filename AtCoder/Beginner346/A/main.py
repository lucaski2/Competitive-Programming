n = int(input())
lst = list(map(int, input().split()))

for i in range(n - 1):
    print(lst[i] * lst[i + 1], end=' ')
print()

