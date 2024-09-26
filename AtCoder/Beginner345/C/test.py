def pr(start, end, reverse):
    if start > end and not reverse:
        return
    if start < end and reverse:
        return
    print(start, end=" ")
    pr(start + 1 if not reverse else start - 1, end, reverse)

def solve(n):
    pr(int(n / 2 + .5), 1, True)
    pr(1 if n % 2 == 0 else 2, int(n / 2 +.5), False)
    print()


