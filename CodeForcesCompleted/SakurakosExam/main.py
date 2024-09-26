
for _ in range(int(input())):
    a, b = map(int, input().split())
    if a == 0 and b == 1:
        print("NO")
    elif (a * 1 + b * 2) % 2 == 1:
        print("NO")
    elif a != 0 or b % 2 == 0:
        print("YES")
    else:
        print("NO")