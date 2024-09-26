a, b = map(int, input().split())

print(-1 if len(set([a, b])) == 1 else 6 - a - b)