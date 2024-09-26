
for _ in range(int(input())):
    x, y = map(int, input().split())
    a = list(bin(x))[2:]
    b = list(bin(y))[2:]
    m = 0
    ind = 0
    while ind < len(a) or ind < len(b):
        if ind >= len(a) and ind < len(b) and b[len(b) - ind - 1] == '1':
            break
        elif ind >= len(b) and ind < len(a) and a[len(a) - ind - 1] == '1':
            break
        elif ind < len(a) and ind < len(b) and a[len(a) - ind - 1] != b[len(b) - ind - 1]:
            break
        m += 1
        ind += 1
    print(pow(2, m))