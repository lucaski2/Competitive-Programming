
for _ in range(int(input())):
    
    x, y, z, vol = map(int, input().split())



    largest = 0

    for a in range(1, x + 1):
        for b in range(1, y + 1):
            if vol % (a * b) != 0:
                continue
            c = vol / (a * b)
            if int(c) == c:
                largest = max(largest, int((x - a + 1) * (y - b + 1) * (z - c + 1)))
    
    print(largest)







