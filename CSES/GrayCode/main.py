n = int(input())

am = 0
for i in range(1 << n):
    print(bin(i)[2:].zfill(n))
    am += 1
