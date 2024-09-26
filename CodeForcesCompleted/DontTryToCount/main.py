for i in range(int(input())):
    n, m = map(int, input().split())
    x = input()
    s = input()

    if s in x * 100:
        for _ in range(100):
            if s in x:
                print(_)
                break
            x *= 2
    
    else:
        print(-1)
    