t = int(input()) 
for _ in range(t):
    n, k = map(int, input().split())
    
    start = n - k + 1
    
    odd_count = (n + 1) // 2 - (start // 2)
    
    if odd_count % 2 == 0:
        print("YES")
    else:
        print("NO")
