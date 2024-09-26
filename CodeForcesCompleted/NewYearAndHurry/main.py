
n, k = map(int, input().split())
a = [0]

for i in range(1, n + 1):
    a.append(a[-1] + 5 * i)

end = 240 - k
for i in range(len(a)):
    if a[i] > end:
        print(i - 1)
        break
else:
    print(n)
