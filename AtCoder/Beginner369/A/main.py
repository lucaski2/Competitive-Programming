a, b = map(int, input().split())
if a == b:
    print(1)
elif abs(a - b) % 2 == 1:
    print(2)
else:
    print(3)