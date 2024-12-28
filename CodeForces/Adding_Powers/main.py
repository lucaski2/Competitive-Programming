from math import pow
from typing import List, Optional, Set

mod = 1000000000 + 7
en = '\n'

def less_or_equal(s, value):
    if not s:
        return None
    it = [x for x in s if x > value]
    if not it:
        return None
    return max(x for x in s if x <= value)

def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    composition = [[] for _ in range(n)]
    ok = True

    for i in range(n):
        max_power = 0
        powers = []
        while pow(k, max_power) <= a[i]:
            max_power += 1
        max_power -= 1
        cur_am = a[i]
        while max_power >= 0:
            if pow(k, max_power) <= cur_am:
                cur_am -= int(pow(k, max_power))
                powers.append(max_power)
            max_power -= 1
        if cur_am != 0:
            ok = False
        composition[i] = powers

    num_needed = [0] * 900
    for powers in composition:
        for am in powers:
            num_needed[am] += 1

    for i in range(900):
        if num_needed[i] > 1:
            ok = False

    print("YES" if ok else "NO")

def main():
    import sys
    t = int(input())
    idx = 1
    for _ in range(t):
        solve()

main()