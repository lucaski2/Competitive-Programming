n = int(input())
a = list(map(int, input().split()))
a.sort()
c = 0
while a[-2] > 0:
    a[-1] -= 1
    a[-2] -= 1
    a.sort()
    c += 1
print(c)