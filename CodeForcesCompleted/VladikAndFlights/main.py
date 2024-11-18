
n, a, b = map(int, input().split())
s = list(map(int, list(input())))
a -= 1
b -= 1
if s[a] == s[b]:
    print(0)
else:
    print(1)
        
