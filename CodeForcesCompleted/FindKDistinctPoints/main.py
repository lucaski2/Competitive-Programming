
for _ in range(int(input())):
    x, y, k = map(int, input().split())
    if k % 2 == 1:
        print(x, y)
        k-=1
    
    for i in range(1, k // 2 + 1):
        print(x + i, y)
        print(x - i, y)
    


