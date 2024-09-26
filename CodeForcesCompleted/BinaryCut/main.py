
for _ in range(int(input())):

    st = input()

    last = st[0]
    cnt = 0
    shortcut_used = False
    for i in range(1, len(st)):
        if st[i] == "1" and last == "0" and not shortcut_used:
            shortcut_used = True

        elif st[i] != last:
            cnt += 1
        last = st[i]
    
    print(cnt + 1)