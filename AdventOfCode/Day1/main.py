
a = [list(map(int, input().split())) for _ in range(1000)]
a, b = [a[i][0] for i in range(1000)], [a[i][1] for i in range(1000)]
a.sort()
b.sort()
print(sum([abs(a[i] - b[i]) for i in range(1000)]))

