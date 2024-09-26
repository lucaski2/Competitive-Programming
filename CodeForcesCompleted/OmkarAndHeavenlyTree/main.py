
for _ in range(int(input())):
    n, m = map(int, input().split())
    used = [False] * (n)
    for i in range(m):
        a,b,c = map(int, input().split())
        a-=1
        b-=1
        c-=1
        used[b] = True
    for i in range(n):
        if not used[i]:
            root = i
            break
    for i in range(n):
        if i != root:
            print(root+1, i+1)


