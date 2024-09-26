
n = int(input())
a = list(map(int, input().split()))
exchanges = [list(map(int, input().split())) for _ in range(n - 1)]

for i in range(n - 1):
    b, c = exchanges[i]
    am = a[i] // b
    a[i + 1] += (am) * c

print(int(a[-1]))




