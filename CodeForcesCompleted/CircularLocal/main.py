import math

def validate_circle(circle):
    n = len(circle)
    circle.insert(0, circle[n - 1])
    circle.append(circle[1])
    for i in range(1, n + 1):
        if circle[i] > circle[i - 1] and circle[i] > circle[i + 1]:
            continue
        elif circle[i] < circle[i - 1] and circle[i] < circle[i + 1]:
            continue
        return False

    
    
    return True 

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    circle = []
    a.sort()
    for i in range(math.ceil(n/2)):
        if i == n // 2 and n % 2 == 1:
            circle.append(a[i])
        else:
            circle.append(a[i])
            circle.append(a[i + math.ceil(n / 2)])
    

    if validate_circle(circle):
        print("YES")
        circle.pop(0)
        circle.pop()
        print(*circle)
    else:
        print("NO")
