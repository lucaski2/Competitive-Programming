
for _ in range(int(input())):

    n, f, k = map(int, input().split())
    a = list(map(int, input().split()))

    favorite = a[f - 1]

    a.sort(reverse=True)

    removed = []
    for i in range(k):
        removed.append(a[0])
        a.pop(0)
    
    if favorite in removed and favorite in a:
        print("MAYBE")
    
    elif favorite in a:
        print("NO")
    
    else:
        print("YES")



