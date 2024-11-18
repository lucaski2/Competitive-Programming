

for _ in range(int(input())):
    n = int(input()) * 2
    s = input()
    
    open_brackets = 0
    close_brackets = 0
    used = False
    ans = 1
    for i in range(n):
        if s[i] == '(':
            open_brackets += 1
            used = False
        else:
            close_brackets += 1
            if open_brackets > close_brackets and not used:
                ans += 1
                used = True
    print(ans)
        