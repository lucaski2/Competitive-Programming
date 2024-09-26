
for _ in range(int(input())):
    n = int(input())
    s = list(input())

    for i in range(n // 2):
        if s[i] == s[n - i - 1]:
            print(n - i * 2)
            break
    else:
        print(0 if n % 2 == 0 else 1)
    

