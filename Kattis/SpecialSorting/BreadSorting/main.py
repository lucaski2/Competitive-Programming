length = int(input())
start = list(map(int, input().split()))
end = list(map(int, input().split()))

reverse = True if end == sorted(end, reverse=True) else False

for i in range(length):
    for j in range(length - 2 - i):
        if reverse:
            if start[i] < start[i + 2] and :
                start[i], start[i + 1], start[i + 2] = start[i + 2], start[i], start[i + 1]

print(start)

