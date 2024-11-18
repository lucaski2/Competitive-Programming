
for _ in range(int(input())):
    n = int(input())
    a = list(input())
    b = list(input())
    counts = a.count('1')
    count2 = a.count('0')
    for i in range(n - 1):
        cur = b[i]
        if counts == 0 or count2 == 0:
            print("NO")
            break

        if cur == '0':
            counts -= 1
        else:
            count2 -= 1
    else:
        print("YES")