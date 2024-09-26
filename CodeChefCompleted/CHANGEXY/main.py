import math


for _ in range(int(input())):
    a, b, k = map(int, input().split())
    
    s = 0
    while b >= a * k:
        if (((a + 1) * k) / b).is_integer():
            a += 1
            s += 1

        else:
            a *= k
            s += 1
        
    print(s + b - a)
