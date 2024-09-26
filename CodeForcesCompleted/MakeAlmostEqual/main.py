
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    
    
    for i in range(57):
        cur = set()
        for j in range(n):
            cur.add(a[j] % (pow(2, i + 1)))
        if len(cur) == 2:
            print(pow(2, i + 1))
            break
    


    

        


