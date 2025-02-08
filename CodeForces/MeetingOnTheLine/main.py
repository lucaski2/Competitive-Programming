from typing import List, Optional
import math

MOD = 1000000007
EN = '\n'


def less_or_equal(s: set, value):
    if not s:
        return None
    greater = [x for x in s if x > value]
    if not greater:
        return max(s)
    return None


def pow_mod(a: int, b: int, m: int) -> int:
    ans = 1
    while b:
        if b & 1:
            ans = (ans * a) % m
        b //= 2
        a = (a * a) % m
    return ans


def solve():
    n = int(input())
    positions = list(map(int, input().split()))
    times = list(map(int, input().split()))

    l, r = 0, 3e8
    ans = 0

    while r - l > 1e-6:
        time = (r + l) / 2
        left_bound = 0
        right_bound = 1e10
        ok = True

        for i in range(n):
            cur = time - times[i]
            if cur < 0:
                ok = False
            else:
                left_bound = max(left_bound, positions[i] - cur)
                right_bound = min(right_bound, positions[i] + cur)

        if left_bound < right_bound and ok:
            r = time
            ans = left_bound
        else:
            l = time

    print(f"{ans:.6f}")


def main():
    t = int(input())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
