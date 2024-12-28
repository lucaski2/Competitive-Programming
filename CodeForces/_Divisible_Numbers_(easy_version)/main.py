from collections import defaultdict
from math import gcd

mod = 1000000000 + 7

mxn = 100005
all_factors = [[] for _ in range(mxn)]


def seive():
    for i in range(2, mxn):
        if not all_factors[i]:
            for j in range(i, mxn, i):
                temp = j
                while temp % i == 0:
                    all_factors[j].append(i)
                    temp //= i


def contains_divisible(a, b, m):
    if a % m == 0:
        return True
    else:
        return (b // m) - (a // m) >= 1


def first_element(a, b, m):
    if a % m == 0:
        return a
    else:
        return a + (m - (a % m))


def solve():
    a, b, c, d = map(int, input().split())
    factors = defaultdict(int)
    a_factors = all_factors[a]
    b_factors = all_factors[b]

    for am in a_factors:
        factors[am] += 1
    for am in b_factors:
        factors[am] += 1

    ok = False
    for cur_a in range(a + 1, c + 1):
        cur_facts = all_factors[cur_a]
        for fact in cur_facts:
            factors[fact] -= 1

        num = 1
        for fact, count in factors.items():
            num *= fact ** count

        if contains_divisible(b + 1, d, num):
            print(cur_a, first_element(b + 1, d, num))
            ok = True
            break

        for fact in cur_facts:
            factors[fact] += 1

    if not ok:
        print("-1 -1")


if __name__ == "__main__":

    
    seive()
    for _ in range(int(input())):
        solve()