
cur = int(input())
while cur != 0:
    a = [-1 for _ in range(32)]
    for _ in range(cur):
        inp = input().split()
        inp[1] = 31 - int(inp[1])
        if len(inp) == 3:
            inp[2] = 31 - int(inp[2])
        
        if inp[0] == "SET":
            a[inp[1]] = 1
        elif inp[0] == "CLEAR":
            a[inp[1]] = 0
        elif inp[0] == "OR":
            if a[inp[1]] == 1 or a[inp[2]] == 1:
                a[inp[1]] = 1
            elif a[inp[1]] == -1 or a[inp[2]] == -1:
                a[inp[1]] = -1
            
            else:
                a[inp[1]] = 0
        else:
            if a[inp[1]] == -1 or a[inp[2]] == -1:
                a[inp[1]] = -1
            else:
                a[inp[1]] = a[inp[1]] & a[inp[2]]
    for i in range(32):
        print(a[i] if a[i] != -1 else "?", end="")
    print()
    cur = int(input())

        



