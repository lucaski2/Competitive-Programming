length = int(input())
inp = input().split()

if length >= 13:
    print(inp[12])

else:
    print(inp[13 % length - 1])