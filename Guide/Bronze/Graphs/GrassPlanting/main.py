inp = open("planting.in", "r")
out = open("planting.out", "w")

n = int(inp.readline())

arr = [0] * n
for _ in range(n - 1):
    a, b = map(int, inp.readline().split())
    arr[a - 1] += 1
    arr[b - 1] += 1

print(max(arr) + 1, file=out)