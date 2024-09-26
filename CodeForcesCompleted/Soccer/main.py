

for _ in range(int(input())):
    a, b = map(int, input().split())
    c, d = map(int, input().split())
    if a <= b and c >= d:
        print("NO")
    
    elif b <= a and d >= c:
        print("NO")
    
    else:
        print("YES")

    