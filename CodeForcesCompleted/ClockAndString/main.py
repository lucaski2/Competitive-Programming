
for _ in range(int(input())):
    a, b, c, d = list(map(int, input().split()))
    st1 = sorted([a, b])
    st2 = sorted([c, d])

    if a == c or b == d or a == d or b == c:
        print("YES")
    else:
        last = -1
        for i in range(1, 13):
            if last in st1 and i in st1:
                print("NO")
                break
            elif last in st2 and i in st2:
                print("NO")
                break
            else:
                if i in st1 or i in st2:
                    last = i
        
        else:
            print("YES")



