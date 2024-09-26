lst = list(map(int, input().split()))

for i in range(len(lst)):
    for j in range(len(lst) - 1):
        if lst[j] > lst[j + 1]:
            lst[j], lst[j + 1] = lst[j + 1], lst[j]
    
            print(*lst)
            if lst == [1, 2, 3, 4, 5]:
                break