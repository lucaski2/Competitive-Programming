n, m = map(int, input().split())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

c = list(sorted(a + b))

for i in range(n + m):
    if c[i] in a and i < n + m - 1 and c[i + 1] in a:
        print("Yes")
        exit()
    if c[i] in a and i > 0 and c[i - 1] in a:
        print("Yes")
        exit()
print("No")
