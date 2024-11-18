
n = int(input())


for i in range(n // 2):
    print(i + 1, end=' ')
    print(n - i, end=' ')
if n % 2 == 1:
    print(n // 2 + 1)
else:
    print()