
    

for _ in range(int(input())):
    a = list(map(int, input().split()))
    a, b = a[:4], a[4:]
    print(win(a, b))
    