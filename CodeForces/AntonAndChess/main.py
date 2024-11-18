n = int(input())
x, y = map(int, input().split())

ok = False
for _ in range(n):
    a, b, c = input().split()
    b = int(b) 
    c = int(c)

    if a == 'R' and (x == b or y == c):
        ok = True
    elif a == 'B' and abs(x - b) == abs(y - c):
        ok = True   
    elif a == 'Q' and (x == b or y == c or abs(x - b) == abs(y - c)):
        ok = True

print('YES' if ok else 'NO')