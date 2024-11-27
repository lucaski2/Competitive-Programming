
def calc(s):
    ret = 0
    for i in range(1, len(s) + 1):
        ret += len(set([s[j:j + i] for j in range(len(s) - i + 1)]))
    return ret

for _ in range(int(input())):
    s = list(input())
    n = len(s)

    for i in range(n - 2):
        if len(set(s[i:i + 3])) == 3:
            print(''.join(s[i:i + 3]))
            break
    else:
        for i in range(n - 1):
            if len(set(s[i:i + 2])) == 1:
                print(''.join(s[i:i + 2]))
                break
        else:
            print(-1)


