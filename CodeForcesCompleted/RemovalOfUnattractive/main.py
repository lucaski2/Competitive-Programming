
for _ in range(int(input())):
    n = int(input())
    s = list(input())
    counts = {}
    for i in range(n):
        if s[i] in counts:
            counts[s[i]] += 1
        else:
            counts[s[i]] = 1
    counts = list(sorted(counts.items(), key=lambda x: x[1], reverse=True))
    cur = counts[0][1]
    am = max(0 if n % 2 == 0 else 1, cur - n + cur)
    print(am)