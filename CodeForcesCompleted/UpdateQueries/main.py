
for i in range(int(input())):
    n, m = map(int, input().split())

    s = list(input())

    indices = list(sorted(list(set(list(map(int, input().split()))))))
    c = list(reversed(sorted(input())))
    
    for ind in indices:
        s[ind - 1] = c.pop()
    
    print("".join(s))
    





