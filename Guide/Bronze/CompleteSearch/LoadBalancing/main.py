inp = open("balancing.in", "r")
out = open("balancing.out", "w")

n, b = list(map(int, inp.readline().strip().split()))

coords = []

for i in range(n):
    x, y = list(map(int, inp.readline().strip().split()))

    
    coords.append((x, y))

lowest = 1000000


for i in range(2, b + 1, 2):
    for j in range(2, b + 1, 2):
        counts = [0, 0, 0, 0]
        for c in coords:
            x, y = c
            if x < i and y < j:
                counts[0] += 1
            elif x < i and y > j:
                counts[1] += 1
            elif x > i and y < j:
                counts[2] += 1
            elif x > i and y > j:
                counts[3] += 1
        if max(counts) < lowest:
            lowest = max(counts)

print(lowest, file=out)