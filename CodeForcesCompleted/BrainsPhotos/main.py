n, m = map(int, input().split())

inp = [input().split() for _ in range(n)]
inp = [inp[i][j] for i in range(n) for j in range(m)]
if "C" in inp or "M" in inp or "Y" in inp:
    print("#Color")
else:
    print("#Black&White")