


for _ in range(int(input())):
    
    n = int(input())
    lst = list(map(int, input().split()))


    s = 0
    lowest = 0
    for i in range(n):
        s += lst[i]
        lowest = min(lowest, s)
    
    print(s - lowest * 2)




