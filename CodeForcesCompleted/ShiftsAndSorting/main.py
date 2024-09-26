
for _ in range(int(input())):
    s = list(input())
    s.reverse()
    while s and s[-1] == '0':
        s.pop()
    s.reverse()

    amount_zero = 0
    ans = 0
    for i in range(len(s)):
        if s[i] == '0':
            ans += i + 1 - amount_zero
            amount_zero += 1
    print(ans)
