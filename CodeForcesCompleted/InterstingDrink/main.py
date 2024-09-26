
def binary_search(a, x):
    l, r = 0, len(a)
    while l < r:
        m = (l + r) // 2
        if a[m] <= x:
            l = m + 1
        else:
            r = m
    return l

n = int(input())
a = list(map(int, input().split()))
a.sort()

q = int(input())
for _ in range(q):
    print(binary_search(a, int(input())))

