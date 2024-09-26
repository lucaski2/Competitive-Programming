n, m = map(int, input().split())
s = 0
for i in range(n + 1):
    s += (i & m).bit_count()
    print((i & m).bit_count())


print(s)
