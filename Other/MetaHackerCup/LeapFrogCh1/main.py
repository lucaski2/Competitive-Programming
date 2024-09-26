
def solve():
    a = list(input())
    n = len(a)
    num_betas = a.count("B")
    if num_betas == (n - 1) or num_betas < (n - 1) / 2:
        return "N"
    else:
        return "Y"

for i in range(int(input())):
    print("Case #" + str(i + 1) + ":", solve())
