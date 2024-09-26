
for _ in range(int(input())):
    n = int(input())
    am = 0
    am += n // 4
    n %= 4
    am += n // 2
    n %= 2
    print(am)
