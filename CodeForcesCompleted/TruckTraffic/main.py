n, q = list(map(int, input().split()))

view = list(input())

spaces = view.count('.')
t = len(view) - spaces

for _ in range(q):
    num = int(input())


    largest = t
    for i in range(len(view)):
        cur = 0
        for j in range(i, min(i + num, len(view))):
            if view[j] == '.':
                cur += 1
        
        if cur + t > largest:
            largest = cur + t
    
    print(largest)


