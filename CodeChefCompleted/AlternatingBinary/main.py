
for _ in range(int(input())):
    n = int(input())
    st = list(map(int, list(input())))
    offset = 0
    last = st[0]
    c = 0
    for i in range(1, n):
        if offset == 1:
            st[i] = 1 if st[i] == 0 else 0
        
        if st[i] == last:
            offset += 1
            offset %= 2
            c += 1
        
        last = 0 if last == 1 else 1
    
    print(c)






