

n, k = map(int, input().split())
lst = list(map(int, input().split()))

lst.sort()

lowest = 1000000000000

for i in range(k + 1):
    if abs(lst[i] - lst[i + n - k - 1]) < lowest:
        lowest = abs(lst[i] - lst[i + n - k - 1])



print(lowest)

