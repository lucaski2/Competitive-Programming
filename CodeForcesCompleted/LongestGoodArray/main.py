
def binary_search(diff):
    l, r = 1, 1000000
    while l < r:
        mid = (l + r) // 2
        am = (1 + mid) * mid // 2

        if am >= diff:
            r = mid
        else:
            l = mid + 1
    return l

for _ in range(int(input())):
    a, b = map(int, input().split())
    space = abs(a - b) + 1
    print(binary_search(space))