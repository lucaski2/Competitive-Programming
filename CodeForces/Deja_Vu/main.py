import math
from collections import defaultdict
import sys

MOD = 10**9 + 7

def solve():
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    amounts = defaultdict(list)
    
    for i in range(n):
        am = 2**35
        while a[i] % am != 0:
            am //= 2
        amounts[int(math.log2(am))].append(i)
    queries = list(map(int, input().split()))
    for i in range(q):
        am = queries[i]
        for key in sorted(amounts.keys(), reverse=True):  # Iterate in descending order of keys
            if key >= am and amounts[key]:
                for ind in amounts[key]:
                    a[ind] += 2**(am - 1)
                    amounts[am - 1].append(ind)
                amounts[key] = []  # Clear the list for the current key

    print(" ".join(map(str, a)))

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()