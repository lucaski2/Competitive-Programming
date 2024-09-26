# cook your dish here
a = list(map(int, input().split()))
s = 0
for i in range(3):
    s += max(0, 5 - a[i])
print(s)


