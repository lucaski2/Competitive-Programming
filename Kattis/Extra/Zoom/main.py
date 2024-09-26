N, length = list(map(int, input().split()))
inp = list(map(int, input().split()))

for i in range(length - 1, N, length):
    print(inp[i], end=" ")

print()