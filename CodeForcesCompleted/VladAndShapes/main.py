
for _ in range(int(input())):
    n = int(input())
    a = [list(input()) for _ in range(n)]

    cnt = 0
    for a in a:
        if cnt > 0:
            print("SQUARE" if a.count("1") == cnt else "TRIANGLE")
            break
        
        cnt = a.count("1")




