
for _ in range(int(input())):
    a = input()
    count = 0
    if a[0] != 'a':
        count += 1
    if a[1] != 'b':
        count += 1
    if a[2] != 'c':
        count += 1
    print("YES" if count <= 2 else "NO")