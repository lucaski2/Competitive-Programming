
def gcd(a, b):
    if b == 0:
        return a

    return gcd(b, a % b)


def diff(a):
    ret = [a[0]]
    for i in range(1, len(a)):
        ret.append(a[i] - a[i-1])
    return ret


for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    if n == 1:
        print(1)
        continue
    a.sort()
    m = a[0]
    for i in range(n):
        a[i] = a[i] - m
    gc = a[0]
    for i in range(1, n):
        gc = gcd(a[i], gc)
    
    for i in range(n):
        a[i] = a[i] // gc
    last = -1
    used = False
    calc1 = 0
    a.append(a[-1] + 1)
    for i in range(n):
        calc1 += a[-1] - a[i]
    a.pop()
    a = [-1] + a
    for i in range(n, 0, -1):
        if a[i] != a[i - 1] + 1:
            a.insert(i, a[i] - 1)
            break
    else:
        print(calc1)
        continue
    a.pop(0)
    calc2 = 0
    for i in range(n):
        calc2 += a[-1] - a[i]
    
    print(min(calc1, calc2))
