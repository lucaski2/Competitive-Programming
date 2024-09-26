
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    m = int(input())
    a_counts = {}
    for i in range(n):
        if a[i] in a_counts:
            a_counts[a[i]].append(i)
        else:
            a_counts[a[i]] = [i]
    a_counts = list(sorted(a_counts.values()))

    for _ in range(m):
        s = list(input())
        if len(s) != n:
            print("NO")
            continue
        counts = {}
        for i in range(n):
            if s[i] in counts:
                counts[s[i]].append(i)
            else:
                counts[s[i]] = [i]
        counts = list(sorted(counts.values()))

        if counts == a_counts:
            print("YES")
        else:
            print("NO")

