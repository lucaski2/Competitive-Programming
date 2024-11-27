
for _ in range(int(input())):
    w, b = map(int, input().split())
    w, b = min(w, b), max(w, b)
    layer = 1
    while w >= layer or b >= layer:
        if w < layer + layer + 1 and b >= layer + layer + 1:
            b -= layer + layer + 1
            layer += 2
        
        elif b < layer + layer + 1 and w >= layer + layer + 1:
            w -= layer + layer + 1
            layer += 2
        
        else:
            if w >= layer:
                w -= layer
            else:
                b -= layer
            layer += 1
    
    print(layer - 1)

        