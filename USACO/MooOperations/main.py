
def works(st):
    if st[1] != "O":
        return -1
    ans = 0
    if st[0] != "M":
        ans += 1
    if st[-1] != "O":
        ans += 1
    return ans

for _ in range(int(input())):
    s = list(input())
    n = len(s)
    ans = float('inf')
    for i in range(len(s) - 2):
        cur = works(s[i:i+3])
        if cur != -1:
            ans = min(ans, cur + n - 3)
    print(ans if ans != float('inf') else -1)

