
for _ in range(int(input())):
    n = int(input())
    if n <= 6 or (n % 3 == 0 and n <= 9):
        print("NO")
        continue
    print("YES")
    if (n - 3) % 3 != 0:
        print(1, 2, n - 3)
    else:
        print(1, 4, n - 5)    