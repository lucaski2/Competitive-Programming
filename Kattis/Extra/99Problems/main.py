import math
inp = int(input())

def solve(num):
    if (num < 100):
        print(99)
        return

    print(int((math.floor(num / 100.0 + 0.01 + 0.5) - 0.01) * 100))


solve(inp)