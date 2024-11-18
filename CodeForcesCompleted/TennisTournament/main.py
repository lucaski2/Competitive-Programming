from math import log2

n, b, p = map(int, input().split())
towels = n * p
matches = 0
am = 0
while n > 1:
    people = 2 ** int(log2(n))
    matches += people // 2
    n -= people // 2

print(matches * b * 2 + matches, towels)

