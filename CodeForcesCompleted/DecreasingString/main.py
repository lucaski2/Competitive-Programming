
for _ in range(int(input())):
    s = list(input())
    n = int(input())
    cur_len = len(s)
    while n > cur_len:
        n -= cur_len
        cur_len -= 1
    # print(cur_len, n)
    si = [s[0]]
    cur_s = len(s)
    for i in range(1, len(s)):
        while cur_s > cur_len and len(si) != 0 and s[i] < si[-1]:
            si.pop()
            cur_s -= 1
        si.append(s[i])
    # print(si)
    while cur_s > cur_len:
        si.pop()
        cur_s -= 1
    
    print(si[n - 1], end='')
print()

