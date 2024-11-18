
for _ in range(int(input())):
    n = int(input())
    print((pow(2, n // 3 + 1, 3359232) - 2) % 3359232)