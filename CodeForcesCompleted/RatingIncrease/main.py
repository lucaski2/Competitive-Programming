for _ in range(int(input())):
    n = list(input())
    for i in range(1, len(n)):
        a, b = n[:i], n[i:]
        if a[0] != "0" and b[0] != "0":
            a, b = int("".join(a)), int("".join(b))
            if a < b and a > 0 and b > 0:
                print(a, b)
                break
    else:
        print(-1)