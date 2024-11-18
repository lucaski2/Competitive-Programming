
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

a, b = map(int, input().split())

for i in range(a, b + 1):
    for j in range(i + 1, b + 1):
        for k in range(j + 1, b + 1):
            if i != j and j != k and i != k and gcd(i, j) == 1 and gcd(j, k) == 1 and gcd(i, k) != 1:
                print(i, j, k)
                exit()
print(-1)