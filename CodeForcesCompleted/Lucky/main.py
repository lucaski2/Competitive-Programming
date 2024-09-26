
for _ in range(int(input())):
    a = list(input())
    a, b = a[:3], a[3:]
    s1, s2 = 0, 0
    for i in range(3):
        s1 += int(a[i])
        s2 += int(b[i])
    print("YES" if s1 == s2 else "NO")