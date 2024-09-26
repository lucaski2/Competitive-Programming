
n = int(input())

s = list(input())
m = float('inf')
for i in range(1, n + 1):
    cur_s = set()
    for j in range(n - i + 1):
        if "".join(s[j:j + i]) in cur_s:
            break
        cur_s.add(''.join(s[j:j + i]))
    else:
        m = min(m, i)
print(m)

    


