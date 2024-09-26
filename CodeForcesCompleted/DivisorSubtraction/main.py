n = int(input())
s = 0
if n % 2 == 1:
    for i in range(3, int(n**0.5) + 1):
        if n % i == 0:
            s += 1
            n -= i
            break
    else:
        s = 1
        n = 0

s += n // 2
print(s)




