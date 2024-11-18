
cur = 0
n = int(input())
while n > 0:
    am = min(n, 2)
    print(am * chr(ord('a') + cur), end='')
    n -= am
    cur += 1
    cur %= 2
print()