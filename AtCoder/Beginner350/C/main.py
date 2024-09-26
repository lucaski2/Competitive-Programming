
n = int(input())
a = list(map(int, input().split()))

indexes = [0] * n
for i in range(n):
    indexes[a[i] - 1] = i

swaps = []

for i in range(n):
    if indexes[i] != i:
        # swap them in indexes and in a
        a[i], a[indexes[i]] = a[indexes[i]], a[i]
        indexes[a[indexes[i]] - 1] = indexes[i]

        swaps.append((i, indexes[i]))

print(len(swaps))
for i in swaps:
    for s in i:
        print(s + 1, end=' ')
    print()










