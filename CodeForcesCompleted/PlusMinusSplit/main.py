
for _ in range(int(input())):
    n = int(input())
    a = list(input())
    c1 = a.count('+')
    c2 = a.count('-')
    print(abs(c1-c2))
